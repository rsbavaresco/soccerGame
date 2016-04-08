#include <Windows.h>
#include <gl\glut.h>
#include <math.h>
#include "Ground.h"
#include "Camera.h"
#include "Goal.h"
#include "Ball.h"
#include "Player.h"
#include "Message.h"

int width = 800, height = 400;
int roundCount = 0; // máximo 3
int score = 0; // 1 ponto por gol
const int consNumberPlayers = 4;
int power = 0;
int CURRENTSTATUS = 0;
float* kickDirection;
bool isGodView = false;

Camera camera;
Ground ground;
Goal goal;
Ball ball;
Player mainPlayer;
Player goalkeeper;
Player players[consNumberPlayers];
Message message;

void animation(void);
void checkCollision(void);
void display(void);
void keyboard(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void resetCamera(void);
void init(void);
void verifyGameStatus(void);
void writeText(void);

enum STATUS
{
	FINALGAME = 1,
	KICK = 2,
	RUN = 3,
};

void animation(void)
{
	goalkeeper.move();

	for (int i = 0; i < consNumberPlayers; i++)
	{
		players[i].move();
	}

	if (CURRENTSTATUS == STATUS::KICK)
	{
		if (ball.getDirectionZ() > ground.getZF()-7.0)
		{
			ball.move();
		}
		else
		{
			ball.setCanDraw(false);
			CURRENTSTATUS = STATUS::RUN;
		}
	}

	glutPostRedisplay();
	Sleep(10);
}

void checkCollision(void)
{
	bool collided = false;

	if (CURRENTSTATUS == STATUS::KICK)
	{
		if (ball.getDirectionZ() < ground.getZF() - 5.0f ||
			ball.getDirectionX() < ground.getXI() || 
			ball.getDirectionX() > ground.getXF() ||
			ball.getDirectionZ() > ground.getZI())
		{
			ball.setCanDraw(false);
			float up = 1.0;
			if (isGodView)
				up = 10.0;

			// colisão com goleiro
			if (ball.getDirectionZ() < goalkeeper.getZI() &&
				ball.getDirectionX() >= goalkeeper.getXI() &&
				ball.getDirectionX() <= goalkeeper.getXF())
			{
				collided = true;
				message.newMessage("Defendeuuuuuuu!!!");
			}
			else
			{
				// colisão com a goleira
				if (ball.getDirectionX() >= goal.getXI()+0.5 &&
					ball.getDirectionX() <= goal.getXF()-0.5)
				{
					score++;
					collided = true;
					message.newMessage("GOOOOOOOOOL!!!");
				}
				else
				{
					collided = true;
					message.newMessage("Pra foraaaaa!!!");
				}
			}
			CURRENTSTATUS = STATUS::RUN;
		}
	}
	else if (CURRENTSTATUS == STATUS::RUN)
	{
		float mxi = mainPlayer.getXI();
		float mxf = mainPlayer.getXF();
		float mzi = mainPlayer.getZI();
		float mzf = mainPlayer.getZF();

		// colisão com jogadores
		for (int i = 0; i < consNumberPlayers; i++)
		{
			// pela frente ou por trás
			if (((mzf < players[i].getZI()) && (mzf > players[i].getZF())) || 
				((mzi < players[i].getZI()) && (mzi > players[i].getZF())))
			{
				float pxi = players[i].getXI();
				float pxf = players[i].getXF();

				// pela esquerda ou direita
				if (((mxi < pxf) && (mxi > pxi)) || ((mxf > pxi) && (mxf < pxf)))
				{
					roundCount++;
					collided = true;
					message.newMessage("Voce perdeu a bola!");
					break;
				}
			}
		}

		// fora do campo
		if (mxi < ground.getXI() ||
			mxf > ground.getXF() ||
			mzi > ground.getZI() ||
			mzf < ground.getZF())
		{
			roundCount++;
			collided = true;
			message.newMessage("Voce nao deve sair do campo!");
		}
	}

	if (collided)
	{
		resetCamera();
	}
}

void display(void)
{
	// limpa a janela com a cor de limpeza corrente
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	camera.rotate();
	camera.translate();
	camera.look();

	// desenha o campo
	ground.draw();
	ground.drawLines(0.2f);

	// desenha a goleira
	goal.draw(0.2f);

	// desenha o jogador principal
	if (isGodView)
	{
		mainPlayer.draw();
	}

	// desenha o goleiro
	goalkeeper.draw();

	// desenha os jogadores
	for (int i = 0; i < consNumberPlayers; i++)
	{
		players[i].draw();
	}

	if (ball.getCanDraw())
	{
		glPushMatrix();
		ball.rotate();
		ball.translate();
		ball.draw();
		glPopMatrix();
	}

	// atualiza as variáveis do jogador principal (câmera)
	mainPlayer.setXI(camera.getPlayerDirection()[0]);
	mainPlayer.setXF(camera.getPlayerDirection()[0] + 0.5f);
	mainPlayer.setYI(-1.0f);
	mainPlayer.setYF(1.0f);
	mainPlayer.setZI(camera.getPlayerDirection()[2]);
	mainPlayer.setZF(camera.getPlayerDirection()[2] + 0.5);

	checkCollision();
	verifyGameStatus();

	if (message.isVisible())
	{
		message.draw();
	}

	glFlush();
}

void keyboard(int key, int x, int y)
{
	if (isGodView) return;
	if (CURRENTSTATUS == STATUS::KICK) return;

	switch (key)
	{
	case GLUT_KEY_UP:
		camera.moveForward();
		break;

	case GLUT_KEY_DOWN:
		camera.moveBackward();
		break;

	case GLUT_KEY_LEFT:
		camera.turnsLeft();
		break;

	case GLUT_KEY_RIGHT:
		camera.turnsRight();
		break;
	}
	CURRENTSTATUS = STATUS::RUN;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1': // movimento da bola rasteira
		power = 0;
		break;
	case '2': // movimento da bola para o meio do gol
		power = 2;
		break;
	case '3': // movimento da bola mais para cima do gol
		power = 4;
		break;
	case 32: // barra-de-espaço
		{
			ball = Ball(camera.getPlayerDirection()[0], power, camera.getPlayerDirection()[2]);
			ball.setVision(camera.getVision()[0], camera.getVision()[1], camera.getVision()[2]);
			ball.setAngle(-camera.getPlayerAngle()[1]);
			ball.setCanDraw(true);
			ball.setGodView(isGodView);
			CURRENTSTATUS = STATUS::KICK;
			roundCount++;
			break;
		}
	case 27: // ESC
		exit(0);
		break;
	case 'Q': //Q
		exit(0);
		break;
	case 'm': // visão godview
		if (!isGodView)
		{
			camera.setEye(15.0, 18.0,2.85);
			camera.setDirection(0.0, 0.0, 10.0);
			camera.setAngle(0.0, 722.0);
			camera.setCenter(2.7,4.0,3.0);
			message.setVisible(false);
		}
		else
		{
			float* playerDirection = camera.getPlayerDirection();
			float* playerAngle = camera.getPlayerAngle();
			camera.setEye(0.0, 0.0, 0.0);
			camera.setDirection(playerDirection[0], playerDirection[1], playerDirection[2]);
			camera.setAngle(playerAngle[0], playerAngle[1]);
			camera.setCenter(0.0, 0.0, -1.0);
		}
		isGodView = !isGodView;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void resetCamera(void)
{
	camera = Camera();
	camera.setAngle(0.0f, 0.0f);
	camera.setCenter(0.0f, 0.0f, -1.0f);
	camera.setDirection(0.0f, 0.0f, 20.0f);
	camera.setEye(0.0f, 0.0f, 0.0f);
	camera.setUp(0.0f, 1.0f, 0.0f);
	camera.setVision(0.0f, 1.0f, 0.0f);
	camera.setPlayerAngle();
	camera.setPlayerDirection();
	isGodView = false;
}

void verifyGameStatus(void)
{
	if (roundCount == 3)
	{
		glutPostRedisplay();
		char* msg = "Fim de Jogo - Voce ganhou!";
		if (score == 0)
			msg = "Fim de Jogo - Voce perdeu!";
		float center = -1.0;
		if (isGodView) center = 0.0;
		message.newMessage(msg);
		roundCount = 0;
		score = 0;
	}
}

void init(void)
{
	// inicia propriedades de cor de fundo
	glClearColor(0.0, 0.0, 0.0, 1.0); // cor do fundo

	// modo definição de matriz de visualização
	glMatrixMode(GL_PROJECTION);
	// limpa matrizes
	glLoadIdentity();

	// define as variáveis iniciais do campo
	ground = Ground(-12.0f, 12.0f, -1.0f, -1.0f, 20.0f, -20.0f);
	ground.setColor(Color(0, 255, 0));
	ground.setColorLines(Color(255, 255, 255)); 

	// define as variáveis iniciais da câmera
	resetCamera();

	// define as variáveis iniciais da goleira
	goal = Goal(-3.5f, 3.5f, -1.0f, 2.0f, -19.8f, -20.0f);
	goal.setColor(Color(255, 255, 255));

	// define as variáveis iniciais do jogador principal
	mainPlayer.setColor(Color(255, 255, 255));

	// define as variáveis iniciais do goleiro
	goalkeeper = Player(-0.25f, 0.25f, -1.0f, 1.0f, -19.5f, -20.0f);
	goalkeeper.setColor(Color(0, 0, 255));
	goalkeeper.setMaxMoveNumber(60);

	// define as variáveis iniciais dos jogadores
	players[0] = Player(-4.0f, -3.5f, -1.0f, 1.0f, 0.5f, 0.0f);
	players[0].setColor(Color(255, 0, 0));
	players[0].setMaxMoveNumber(40);

	players[1] = Player(3.5f, 4.0f, -1.0f, 1.0f, 0.5f, 0.0f);
	players[1].setColor(Color(255, 0, 0));
	players[1].setMaxMoveNumber(25);

	players[2] = Player(-8.0f, -7.5f, -1.0f, 1.0f, 10.0f, 9.5f);
	players[2].setColor(Color(255, 0, 0));
	players[2].setMaxMoveNumber(35);

	players[3] = Player(7.5f, 8.0f, -1.0f, 1.0f, 10.0f, 9.5f);
	players[3].setColor(Color(255, 0, 0));
	players[3].setMaxMoveNumber(45);

	// inicializa as variáveis da mensagem
	message = Message(100, Color(255, 255, 255), camera.getDirection()[0]-1.0,camera.getDirection()[1]+ 1.0f, camera.getDirection()[2]-5.0f);

	// define câmera com projeção perspectiva
	gluPerspective(45.0, (GLdouble)width/(GLdouble)height, 0.1, 65.0);

	// define look at com valores inicializados na classe Camera
	gluLookAt(camera.getEye()[0], camera.getEye()[1], camera.getEye()[2], 
		camera.getCenter()[0], camera.getCenter()[1], camera.getCenter()[2],
		camera.getUp()[0], camera.getUp()[1], camera.getUp()[2]);

	// já deixa preparado para o modo transformações e renderização de objetos
	glMatrixMode(GL_MODELVIEW);

	// define tamanho da viewport (porção visível da tela)
	glViewport(0, 0, width, height);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	// inicializa glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);

	// cria janela
	glutCreateWindow("Soccer Game 1.0 - by Cassiano Mendes & Rodrigo Bavaresco");
	init();

	// seta funções
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard);
	glutIdleFunc(animation);

	glutMainLoop();
	return 0;
}
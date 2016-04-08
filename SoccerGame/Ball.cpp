#include "Ball.h"
#include <math.h>
Ball::Ball()
{

}

Ball::Ball(float dx, float dy, float dz)
{
	this->directionX = dx;
	this->directionY = dy;
	this->directionZ = dz;
}

void Ball::draw()
{
	
	glColor3ub (255,255,255);
	//glutSolidSphere(1.0, 50, 200);
	GLfloat circle_points = 400.0f;
	GLfloat angle;
	float raiox = 1.0f;
	float raioy = 1.0f;
	glBegin(GL_POLYGON);
		for (int i = 0; i < circle_points; i++) {
			angle = 2*3.141*i/circle_points;
			if (this->isGodView)
				glVertex3f(cos(angle)*raiox, 0.0, sin(angle)*raioy);
			else
				glVertex3f(cos(angle)*raiox, sin(angle)*raioy, 0.0);
		}
	glEnd();
	
	glLineWidth(0.1);
	if (isGodView)
	{
		//centro
		glColor3ub (0.0,0.0,0.0);
		glBegin(GL_POLYGON);
			glVertex3f(-0.2, 0.0, -0.2);
			glVertex3f(0.2, 0.0, -0.2);
			glVertex3f(0.3,0.0, 0.2);
			glVertex3f(0.0, 0.0, 0.4);
			glVertex3f(-0.3, 0.0, 0.2);
		glEnd();
		//topo
		glBegin(GL_POLYGON);
			glVertex3f(0.2,0.0, 1.0);
			glVertex3f(0.3,0.0, 0.9);
			glVertex3f(0,0.0, 0.8);
			glVertex3f(-0.3,0.0, 0.9);
			glVertex3f(-0.2,0.0, 1.0);
		glEnd();
		//esquerda superior
		glBegin(GL_POLYGON);
			glVertex3f(-0.8, 0.0,0.65);
			glVertex3f(-0.6,0.0,0.65);
			glVertex3f(-0.7,0.0,0.4);
			glVertex3f(-0.9,0.0,0.2);
			glVertex3f(-1.0,0.0,0.3);
		glEnd();
		//esquerda inferior
		glBegin(GL_POLYGON);
			glVertex3f(-0.7,0.0,-0.7);
			glVertex3f(-0.75,0.0,-0.5);
			glVertex3f(-0.4,0.0,-0.5);
			glVertex3f(-0.25,0.0,-0.8);
			glVertex3f(-0.5,0.0,-0.9);
		glEnd();
		//direita ifnerior
		glBegin(GL_POLYGON);
			glVertex3f(0.75,0.0,-0.7);
			glVertex3f(0.75,0.0,-0.5);
			glVertex3f(0.4,0.0,-0.5);
			glVertex3f(0.25,0.0,-0.8);
			glVertex3f(0.5,0.0,-0.9);
		glEnd();
		//direita superior
		glBegin(GL_POLYGON);
			glVertex3f(0.8,0.0,0.65);
			glVertex3f(0.6,0.0,0.65);
			glVertex3f(0.7,0.0,0.4);
			glVertex3f(0.9,0.0,0.2);
			glVertex3f(1.0,0.0,0.3);
		glEnd();
	
		//linha superior
		glBegin(GL_LINE_STRIP);
			glVertex3f(0.0,0.0,0.4);
			glVertex3f(0.0,0.0,0.8);
		glEnd();
		//linha esquerda superior
		glBegin(GL_LINE_STRIP);
			glVertex3f(-0.3,0.0,0.2);
			glVertex3f(-0.7,0.0,0.4);
		glEnd();
		//linha esquerda inferior
		glBegin(GL_LINE_STRIP);
			glVertex3f(-0.2,0.0,-0.2);
			glVertex3f(-0.4,0.0,-0.6);
		glEnd();
		//linha direita inferior
		glBegin(GL_LINE_STRIP);
			glVertex3f(0.2,0.0,-0.2);
			glVertex3f(0.4,0.0,-0.6);
		glEnd();
		//linha direita superior
		glBegin(GL_LINE_STRIP);
			glVertex3f(0.3,0.0,0.2);
			glVertex3f(0.7,0.0,0.4);
		glEnd();
	}
	else
	{
		//centro
		glColor3ub (0.0,0.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(-0.2, -0.2);
			glVertex2f(0.2, -0.2);
			glVertex2f(0.3, 0.2);
			glVertex2f(0.0, 0.4);
			glVertex2f(-0.3, 0.2);
		glEnd();
		//topo
		glBegin(GL_POLYGON);
			glVertex2f(0.2, 1.0);
			glVertex2f(0.3, 0.9);
			glVertex2f(0, 0.8);
			glVertex2f(-0.3, 0.9);
			glVertex2f(-0.2, 1.0);
		glEnd();
		//esquerda superior
		glBegin(GL_POLYGON);
			glVertex2f(-0.8, 0.65);
			glVertex2f(-0.6, 0.65);
			glVertex2f(-0.7, 0.4);
			glVertex2f(-0.9, 0.2);
			glVertex2f(-1.0, 0.3);
		glEnd();
		//esquerda inferior
		glBegin(GL_POLYGON);
			glVertex2f(-0.7, -0.7);
			glVertex2f(-0.75, -0.5);
			glVertex2f(-0.4, -0.5);
			glVertex2f(-0.25, -0.8);
			glVertex2f(-0.5, -0.9);
		glEnd();
		//direita ifnerior
		glBegin(GL_POLYGON);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.5);
			glVertex2f(0.4, -0.5);
			glVertex2f(0.25, -0.8);
			glVertex2f(0.5, -0.9);
		glEnd();
		//direita superior
		glBegin(GL_POLYGON);
			glVertex2f(0.8, 0.65);
			glVertex2f(0.6, 0.65);
			glVertex2f(0.7, 0.4);
			glVertex2f(0.9, 0.2);
			glVertex2f(1.0, 0.3);
		glEnd();
	
		//linha superior
		glBegin(GL_LINE_STRIP);
			glVertex2f(0.0, 0.4);
			glVertex2f(0.0, 0.8);
		glEnd();
		//linha esquerda superior
		glBegin(GL_LINE_STRIP);
			glVertex2f(-0.3, 0.2);
			glVertex2f(-0.7, 0.4);
		glEnd();
		//linha esquerda inferior
		glBegin(GL_LINE_STRIP);
			glVertex2f(-0.2, -0.2);
			glVertex2f(-0.4, -0.6);
		glEnd();
		//linha direita inferior
		glBegin(GL_LINE_STRIP);
			glVertex2f(0.2, -0.2);
			glVertex2f(0.4, -0.6);
		glEnd();
		//linha direita superior
		glBegin(GL_LINE_STRIP);
			glVertex2f(0.3, 0.2);
			glVertex2f(0.7, 0.4);
		glEnd();
	}
	glFlush();
}

void Ball::move()
{
	this->directionZ -= 0.5f;
}

void Ball::rotate()
{
	glRotatef(this->angle, this->visionx, this->visiony, this->visionz);
}

void Ball::translate()
{	
	float xrotrad = (this->angle / 180 * 3.14159);
	float newA = float(sin(xrotrad)); //x
	this->directionX -= newA;
	glTranslatef(this->directionX, this->directionY-3.0f, this->directionZ+1.0f);
}

void Ball::setGodView(bool isGodView){ this->isGodView = isGodView;  }
float Ball::getDirectionX() { return this->directionX; }
float Ball::getDirectionY() { return this->directionY; }
float Ball::getDirectionZ() { return this->directionZ; }
bool Ball::getCanDraw() { return this->canDraw; }

void Ball::setAngle(float angle) { this->angle = angle; }
void Ball::setDirectionX(float dx) { this->directionX = directionX; }
void Ball::setDirectionY(float dy) { this->directionY = directionY; }
void Ball::setDirectionZ(float dz) { this->directionZ = directionZ; }

void Ball::setVision(float vx, float vy, float vz)
{
	this->visionx = vx;
	this->visiony = vy;
	this->visionz = vz;
}
void Ball::setCanDraw(bool canDraw) { this->canDraw = canDraw; }
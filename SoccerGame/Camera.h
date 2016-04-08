#pragma once

#include <gl\glut.h>
#include <math.h>

class Camera
{
private:
	//Camera View
	float direction[3]; //transla��o
	float vision[3];   //x, y, z para vis�o rota��o
	float angle[2];	   //x e y para rota��o
	
	// Look At view - Valores setados para inicializa��o
	float eye[3];
	float center[3];
	float up[3];

	float playerDirection[3]; //transla��o
	float playerAngle[2]; //x e y para rota��o
	
public:
	Camera();
	void rotate();
	void translate();
	void look();

	void moveForward();
	void moveBackward();
	void turnsRight();
	void turnsLeft();

	void setDirection(float x, float y, float z);
	void setVision(float x, float y, float z);
	void setAngle(float x, float y);
	void setEye(float x, float y, float z);
	void setCenter(float x, float y, float z);
	void setUp(float x, float y, float z);

	void setPlayerAngle();
	void setPlayerDirection();

	float* getDirection();
	float* getVision();
	float* getAngle();

	float* getEye();
	float* getCenter();
	float* getUp();

	float* getPlayerDirection();
	float* getPlayerAngle();

};
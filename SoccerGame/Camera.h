#pragma once

#include <gl\glut.h>
#include <math.h>

class Camera
{
private:
	//Camera View
	float direction[3]; //translação
	float vision[3];   //x, y, z para visão rotação
	float angle[2];	   //x e y para rotação
	
	// Look At view - Valores setados para inicialização
	float eye[3];
	float center[3];
	float up[3];

	float playerDirection[3]; //translação
	float playerAngle[2]; //x e y para rotação
	
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
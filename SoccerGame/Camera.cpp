#include "Camera.h"

#define PI 3.1415926535898

Camera::Camera()
{

}

void Camera::look()
{
	gluLookAt(this->getEye()[0], this->getEye()[1], this->getEye()[2], 
		this->getCenter()[0], this->getCenter()[1], this->getCenter()[2],
		this->getUp()[0], this->getUp()[1], this->getUp()[2]);
}

void Camera::translate()
{
	
	glTranslatef(-this->direction[0], -this->direction[1], -this->direction[2]);
}

void Camera::rotate()
{
	glRotatef(this->angle[1], this->vision[0], this->vision[1], this->vision[2]);
}

void Camera::moveForward()
{
	float yrotrad, xrotrad;
	yrotrad = (this->angle[1] / 180 * PI);
	xrotrad = (this->angle[0] / 180 * PI);
	this->direction[0] += float(sin(yrotrad)); //x
    this->direction[1] -= float(sin(xrotrad)); //y
	this->direction[2] -= float(cos(yrotrad)); //z
	setPlayerDirection();
}

void Camera::moveBackward()
{
	float yrotrad, xrotrad;
	yrotrad = (this->angle[1] / 180 * PI);
	xrotrad = (this->angle[0] / 180 * PI);
	this->direction[0] -= float(sin(yrotrad)); //x
	this->direction[1] += float(sin(xrotrad)); //y
	this->direction[2] += float(cos(yrotrad)); //z
	setPlayerDirection();
}

void Camera::setPlayerDirection()
{
	this->playerDirection[0] = this->direction[0];
	this->playerDirection[1] = this->direction[1];
	this->playerDirection[2] = this->direction[2];
}

void Camera::turnsRight()
{
	float angley = this->angle[1];
    angley += 1.0;
    if (angley > 360)
    {
        angley -= 360;
    }
	this->angle[1] = angley;
	setPlayerAngle();
}

void Camera::turnsLeft()
{
	float angley = this->angle[1];
	angley -= 1.0;
    if (angley < 360)
    {
        angley += 360;
    }
	this->angle[1] = angley;
	setPlayerAngle();
}

void Camera::setPlayerAngle()
{
	this->playerAngle[0] = this->angle[0];
	this->playerAngle[1] = this->angle[1];
}

void Camera::setDirection(float x, float y, float z)
{
	this->direction[0] = x;
	this->direction[1] = y;
	this->direction[2] = z;
}

void Camera::setAngle(float x, float y)
{
	this->angle[0] = x;
	this->angle[1] = y;
}

void Camera::setVision(float x, float y, float z)
{
	this->vision[0] = x;
	this->vision[1] = y;
	this->vision[2] = z;
}

void Camera::setEye(float x, float y, float z)
{
	this->eye[0] = x;
	this->eye[1] = y;
	this->eye[2] = z;
}

void Camera::setCenter(float x, float y, float z)
{
	this->center[0] = x;
	this->center[1] = y;
	this->center[2] = z;
}

void Camera::setUp(float x, float y, float z)
{
	this->up[0] = x;
	this->up[1] = y;
	this->up[2] = z;
}

float* Camera::getEye()
{
	return this->eye;
}

float* Camera::getCenter()
{
	return this->center;
}

float* Camera::getUp()
{
	return this->up;
}

float* Camera::getDirection()
{
	return this->direction;
}

float* Camera::getVision()
{
	return this->vision;
}

float* Camera::getAngle()
{
	return this->angle;
}

float* Camera::getPlayerAngle()
{
	return this->playerAngle;
}

float* Camera::getPlayerDirection()
{
	return this->playerDirection;
}
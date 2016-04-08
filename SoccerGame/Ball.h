#pragma once

#include <gl\glut.h>

class Ball
{
private:
	float directionX;
	float directionY;
	float directionZ;
	float angle;
	float visionx;
	float visiony;
	float visionz;
	bool canDraw;
	bool isGodView;
public:
	Ball();
	Ball(float dx, float dy, float dz);

	void draw();
	void move();
	void rotate();
	void translate();

	float getDirectionX();
	float getDirectionY();
	float getDirectionZ();
	bool getCanDraw();
	
	void setGodView(bool isGodView);
	void setAngle(float angle);
	void setDirectionX(float dx);
	void setDirectionY(float dy);
	void setDirectionZ(float dz);
	void setVision(float vx, float vy, float vz);
	void setCanDraw(bool canDraw);
};
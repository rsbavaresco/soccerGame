#pragma once

#include <gl\glut.h>
#include "Color.h"

class Message
{
private:
	float x;
	float y;
	float z;
	char* msg;
	int duration;
	int countDuration;
	bool visible;
	Color color;
public:
	Message();
	Message(int duration, Color color, float x, float y, float z);

	void newMessage(char* msg);
	void draw();

	bool isVisible();
	void setVisible(bool visible);
};
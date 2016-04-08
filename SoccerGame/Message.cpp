#include "Message.h"

Message::Message()
{

}

Message::Message(int duration, Color color, float x, float y, float z)
{
	this->duration = duration;
	this->countDuration = 0;
	this->color = color;
	this->visible = false;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Message::newMessage(char* msg)
{
	this->msg = msg;
	this->countDuration = 0;
	this->visible = true;
}

void Message::draw()
{
	char* message = this->msg;

	glPushMatrix();

	glColor3ub (color.getR(), color.getG(), color.getB());
	glRasterPos3f(this->x, this->y, this->z);
	while(*message)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*message++);
	}

	glPopMatrix();

	this->countDuration++;
}

bool Message::isVisible()
{
	if (this->visible && (this->countDuration < this->duration))
		return true;
	else
		return false;
}

void Message::setVisible(bool visible) { this->visible = visible; }
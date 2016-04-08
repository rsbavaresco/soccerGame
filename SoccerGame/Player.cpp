#include <gl\glut.h>
#include "Player.h"

Player::Player() : ScenarioObject()
{

}

Player::Player(float xi, float xf, float yi, float yf, float zi, float zf) : ScenarioObject(xi, xf, yi, yf, zi, zf)
{
	this->countMove = 0;
	this->direction = Direction::Left;
}

void Player::draw()
{
	glPushMatrix();
	glColor3ub(this->color.getR(), this->color.getG(), this->color.getB());

	//base
	glBegin(GL_QUADS);
	glVertex3f(xi, yi, zi);	// canto esquerdo (perto)
	glVertex3f(xf, yi, zi);	// canto direito (perto)
	glVertex3f(xf, yi, zf);	// canto direito (longe)
	glVertex3f(xi, yi, zf);	// canto esquerdo (longe)
	glEnd();

	//tampa
	glBegin(GL_QUADS);
	glVertex3f(xi, yf, zi);	// canto esquerdo (perto)
	glVertex3f(xf, yf, zi);	// canto direito (perto)
	glVertex3f(xf, yf, zf);	// canto direito (longe)
	glVertex3f(xi, yf, zf);	// canto esquerdo (longe)
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(xi, yi, zi);	// canto perto baixo
	glVertex3f(xi, yi, zf);	// canto longe baixo
	glVertex3f(xi, yf, zf);	// canto longe alto
	glVertex3f(xi, yf, zi);	// canto esquerdo (longe)
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(xf, yi, zi);	// canto perto baixo
	glVertex3f(xf, yi, zf);	// canto longe baixo
	glVertex3f(xf, yf, zf);	// canto longe alto
	glVertex3f(xf, yf, zi);	// canto perto alto
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(xi, yi, zf);	// canto esquerdo longe baixo
	glVertex3f(xf, yi, zf);	// canto direito longe baixo
	glVertex3f(xf, yf, zf);	// canto direito alto
	glVertex3f(xi, yf, zi);	// canto esquerdo alto
	glEnd();

	glPopMatrix();
}

void Player::switchDirection()
{
	switch (direction)
	{
	case Left:
		direction = Direction::Right;
		break;
	case Right:
		direction = Direction::Left;
		break;
	}
}

void Player::moveLeft()
{
	this->xi -= 0.05f;
	this->xf -= 0.05f;
}

void Player::moveRight()
{
	this->xi += 0.05f;
	this->xf += 0.05f;
}

void Player::move()
{
	if (this->countMove == this->maxMoveNumber)
	{
		switchDirection();
		this->countMove = -this->maxMoveNumber;
	}

	switch (direction)
	{
	case Left:
		moveLeft();
		break;
	case Right:
		moveRight();
		break;
	}

	countMove++;
}

void Player::setMaxMoveNumber(int maxMoveNumber) { this->maxMoveNumber = maxMoveNumber; }


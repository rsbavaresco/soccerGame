#include <gl\glut.h>
#include "Goal.h"

Goal::Goal() : ScenarioObject()
{

}

Goal::Goal(float xi, float xf, float yi, float yf, float zi, float zf) : ScenarioObject(xi, xf, yi, yf, zi, zf)
{
	
}

void Goal::draw(float xi, float xf, float yi, float yf, float zi, float zf)
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

void Goal::drawBar(float xi, float xf, float yi, float yf, float zi, float zf)
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

void Goal::draw(float size)
{
	draw(this->xi - size, this->xi, this->yi, this->yf, this->zi, this->zf);
	draw(this->xf, this->xf + size, this->yi, this->yf, this->zi, this->zf);
	drawBar(this->xi - size, this->xf + size, this->yf, this->yf + size, this->zi, this->zf);
}
#include <gl\glut.h>
#include <math.h>
#include "Ground.h"

#define PI 3.1415926535898

Ground::Ground()
{

}

Ground::Ground(float xi, float xf, float yi, float yf, float zi, float zf) : ScenarioObject(xi, xf, yi, yf, zi, zf)
{
	
}

void Ground::draw()
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(this->color.getR(), this->color.getG(), this->color.getB());
	glVertex3f(this->xi, this->yi, this->zi);	// canto esquerdo (perto)
	glVertex3f(this->xf, this->yi, this->zi);	// canto direito (perto)
	glVertex3f(this->xf, this->yi, this->zf);	// canto direito (longe)
	glVertex3f(this->xi, this->yi, this->zf);	// canto esquerdo (longe)
	glEnd();
	glPopMatrix();
}

void Ground::drawLine(float xi, float xf, float zi, float zf)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(colorLines.getR(), colorLines.getG(), colorLines.getB());
	glVertex3f(xi, this->yi, zi);	// canto direito (perto)
	glVertex3f(xf, this->yi, zi);	// canto direito (perto) + size
	glVertex3f(xf, this->yi, zf);	// canto direito (longe) + size
	glVertex3f(xi, this->yi, zf);	// canto direito (longe)
	glEnd();
	glPopMatrix();
}

void Ground::drawHalfCircle(float lineWidth, GLfloat aux, GLfloat raiox, GLfloat raioz, float zpos)
{
	GLfloat circle_points = 100.0f;
	GLfloat angle;

	glPushMatrix();
	glLineWidth(lineWidth);
	glBegin(GL_LINE_LOOP);
	glColor3f (this->colorLines.getR(), this->colorLines.getG(), this->colorLines.getB());
	for (int i = 0; i <= circle_points; i++) {
		angle = aux*PI*i/circle_points;
		glVertex3f(cos(angle)*raiox, this->yi, zpos + sin(angle)*raioz);
	}
	glEnd();
	glPopMatrix();
}

void Ground::drawLines(float size)
{
	drawLine(this->xi, this->xi - size, this->zi, this->zf);				// linha lateral esquerda
	drawLine(this->xi, this->xf, this->zf, this->zf + size);				// linha de fundo
	drawLine(this->xf, this->xf + size, this->zi, this->zf);				// linha lateral direita
	drawLine(this->xi - size, this->xf + size, this->zi, this->zi + size);	// linha meio campo

	// área menor
	drawLine(this->xi + 6.0f, this->xi + 6.0f + size, this->zf + 4.0f, this->zf);
	drawLine(this->xi + 6.0f, this->xf - 6.0f, this->zf + 4.0f, this->zf + 4.0f + size);
	drawLine(this->xf - 6.0f, this->xf - 6.0f - size, this->zf + 4.0f, this->zf);

	// área
	drawLine(this->xi + 3.0f, this->xi + 3.0f + size, this->zf + 11.0f, this->zf);
	drawLine(this->xi + 3.0f, this->xf - 3.0f, this->zf + 11.0f, this->zf + 11.0f + size);
	drawLine(this->xf - 3.0f, this->xf - 3.0f - size, this->zf + 11.0f, this->zf);

	// semi-círculos
	drawHalfCircle(5.0f, -1.0f, 5.0f, 5.0f, this->zi + 0.1f);
	drawHalfCircle(5.0f, 1.0f, 4.0f, 3.0f, this->zf + 11.1f);
}

Color Ground::getColorLines() { return this->colorLines; }

void Ground::setColorLines(Color color) { this->colorLines = color; }
#include "ScenarioObject.h"

class Ground : public ScenarioObject
{
private:
	Color colorLines;
	void drawLine(float xi, float xf, float zi, float zf);
	void drawHalfCircle(float lineWidth, GLfloat aux, GLfloat raiox, GLfloat raioz, float zpos);
public:
    Ground();
	Ground(float xi, float xf, float yi, float yf, float zi, float zf);
    
	void draw();
    void drawLines(float size);
	
	Color getColorLines();

	void setColorLines(Color color);
};
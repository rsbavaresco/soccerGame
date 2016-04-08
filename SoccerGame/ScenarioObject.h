#pragma once 

#include "Color.h"

class ScenarioObject
{
protected:
	float xi;
	float xf;
	float yi;
	float yf;
	float zi;
	float zf;
	Color color;
public:
	ScenarioObject();
	ScenarioObject(float xi, float xf, float yi, float yf, float zi, float zf);

	float getXI();
	float getXF();
	float getYI();
	float getYF();
	float getZI();
	float getZF();
	Color getColor();

	void setXI(float xi);
	void setXF(float xf);
	void setYI(float yi);
	void setYF(float yf);
	void setZI(float zi);
	void setZF(float zf);
	void setColor(Color color);
};
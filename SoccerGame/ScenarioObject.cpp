#include "ScenarioObject.h"

ScenarioObject::ScenarioObject() {}

ScenarioObject::ScenarioObject(float xi, float xf, float yi, float yf, float zi, float zf)
{
	this->xi = xi;
	this->xf = xf;
	this->yi = yi;
	this->yf = yf;
	this->zi = zi;
	this->zf = zf;
}

float ScenarioObject::getXI() { return this->xi; }

float ScenarioObject::getXF() { return this->xf; }

float ScenarioObject::getYI() { return this->yi; }

float ScenarioObject::getYF() { return this->yf; }

float ScenarioObject::getZI() { return this->zi; }

float ScenarioObject::getZF() { return this->zf; }

Color ScenarioObject::getColor() { return this->color; }

void ScenarioObject::setXI(float xi) { this->xi = xi; }

void ScenarioObject::setXF(float xf) { this->xf = xf; }

void ScenarioObject::setYI(float yi) { this->yi = yi; }

void ScenarioObject::setYF(float yf) { this->yf = yf; }

void ScenarioObject::setZI(float zi) { this->zi = zi; }

void ScenarioObject::setZF(float zf) { this->zf = zf; }

void ScenarioObject::setColor(Color color) { this->color = color; }
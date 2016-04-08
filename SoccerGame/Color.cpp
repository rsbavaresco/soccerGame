#include "Color.h"

Color::Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Color::setR(int r) { this->r = r; }

void Color::setG(int g) { this->g = g; }

void Color::setB(int b) { this->b = b; }

int Color::getR() { return this->r; }

int Color::getG() { return this->g; }

int Color::getB() { return this->b; }
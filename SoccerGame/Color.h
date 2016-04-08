#pragma once

class Color
{
private:
    int r;
    int g;
    int b;
public:
    Color();
    Color(int r, int g, int b);
    void setR(int r);
    void setG(int g);
    void setB(int b);
    int getR();
    int getG();
    int getB();
};
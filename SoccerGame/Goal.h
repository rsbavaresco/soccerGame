#include "ScenarioObject.h"

class Goal : public ScenarioObject
{
private:
	void draw(float xi, float xf, float yi, float yf, float zi, float zf);
	void drawBar(float xi, float xf, float yi, float yf, float zi, float zf);
public:
    Goal();
	Goal(float xi, float xf, float yi, float yf, float zi, float zf);
	void draw(float size);
};
#include "ScenarioObject.h"
#include "Direction.h"

class Player : public ScenarioObject
{
private:
	int countMove;
	int maxMoveNumber;
	Direction direction;

	void switchDirection();
	void moveLeft();
	void moveRight();
public:
	Player();
	Player(float xi, float xf, float yi, float yf, float zi, float zf);

    void draw();
	void move();

	void setMaxMoveNumber(int maxMoveNumber);
};
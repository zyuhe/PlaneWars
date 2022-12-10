#ifndef _OBJECT_H_
#define _OBJECT_H_

/*
base of player, bullet, enemy and supply who has position and speed.
*/

#include "glutSet.h"

class Object {
public:
	Object() {}

	void SetSpeed(int s) { speed = s; }
	float GetX() { return positionX; }
	float GetY() { return positionY; }
	int GetSpeed() { return speed; }

protected:
	float positionX;
	float positionY;
	int speed;
};

#endif
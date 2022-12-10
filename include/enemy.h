#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <ctime>
#include "object.h"

class Enemy : public Object {
public:
	Enemy();
	Enemy(int a);

	void Update();
	void Move();
	void ReduceHP(int aggresivity);
	int GetHealth() { return health; }
	float GetHitBoundary() { return hitBoundary; }
private:
	int angle; // TODO: change move angle 
	int health;
	float hitBoundary;
};

#endif
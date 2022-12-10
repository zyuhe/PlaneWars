#ifndef _BULLETBASE_H_
#define _BULLETBASE_H_

#include <cstring>
#include "glutSet.h"
#include "object.h"
#include "enemyController.h"

class EnemyController;
class BulletBase : public Object {
public:
	BulletBase() {}
	BulletBase(float x, float y, bool ad);
	void Update();
	void Move();
	void SetHit(bool h);
	void upgrade();
	void degrade();
	bool GetHit() { return hit; }
	int GetAggressivity() { return aggressivity; }
	float GetHitBoundary() { return hitBoundary; }
protected:
	int aggressivity;
	bool hit;
	float hitBoundary;
	bool advanced; // true: 3 base bullet, false: 1 base bullet
};

#endif
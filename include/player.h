#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <deque>
#include "object.h"
#include "enemy.h"
#include "bulletBase.h"

class Player : public Object {
public:
	Player();
	Player(float x, float y);

	void Update();
	void Move(bool *keyStates);
	void ReduceHP(int hp);
	void shoot();
	void updateScore(int s);

	void SetAdvance(bool a);
	std::deque<BulletBase>& GetBullets() { return bullets; }
	float GetHitBoundary() { return hitBoundary; }
	int GetHealth() { return health; }
	int GetScore() { return score; }

private:
	std::deque<BulletBase> bullets;
	int shootInterval;
	int score;
	int health;
	float hitBoundary;
	int bulletSize;
	bool advanced;
};

#endif
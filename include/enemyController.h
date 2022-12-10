#ifndef _ENEMYCONTROLLER_H_
#define _ENEMYCONTROLLER_H_

#include <ctime>
#include <deque>
#include "enemy.h"

class EnemyController {
public:
	EnemyController();

	void Create();
	std::deque<Enemy>& GetEnemys() { return enemys; }
private:
	float createInterval;
	std::deque<Enemy> enemys;
};

#endif
#include "enemyController.h"

EnemyController::EnemyController() {
	srand(time(nullptr));
	createInterval = rand() % 100 + 20;
}

// create enemy at random time and radom position.
void EnemyController::Create() {
	if(createInterval-- == 0) {
		enemys.emplace_back(Enemy());
		createInterval = rand() % 100 + 20;
	}
	for (auto& e : enemys) {
		e.Move();
		if (enemys.size() > 40) {
			enemys.pop_front();
		}
	}
} 
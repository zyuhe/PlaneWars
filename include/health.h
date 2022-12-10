#ifndef _HEALTH_H_
#define _HEALTH_H_

/*
supply for player to increase HP
max HP = 100
*/

#include "supplyBase.h"

class Health : public SupplyBase {
public:
	Health();
	void Update();
	int GetHealth() { return health; }
private:
	int health;
};

#endif
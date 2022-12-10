#ifndef _MAGAZINE_H_
#define _MAGAZINE_H_

/*
supply for player to upgrade bullet (1->3)
*/

#include "supplyBase.h"

class Magazine : public SupplyBase {
public:
	Magazine();
	void Update();
private:
	int level;
};

#endif
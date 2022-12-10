#ifndef _SUPPLIER_H_
#define _SUPPLIER_H_

/*
create heart or bullet upgrader
*/

#include <ctime>
#include "glutSet.h"
#include "health.h"
#include "magazine.h"

class Supplier {
public:
	Supplier();
	void createSupply();
	Health*& GetHealth() { return health; }
	Magazine*& GetMagazine() { return magazine; }
private:
	int countH;
	int createInterval;
	Health *health;
	Magazine *magazine;
};

#endif
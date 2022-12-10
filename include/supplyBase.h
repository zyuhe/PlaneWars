#ifndef _SUPPLYBASE_H_
#define _SUPPLYBASE_H_

/* 
base of heart and bullet upgrader
*/

#include <ctime>
#include "glutSet.h"
#include "object.h"

class SupplyBase : public Object {
public:
	SupplyBase();
	void Move();
	virtual void Update() = 0;
	void SetArrived(bool a);
	bool GetArrived() { return arrived; }
	float GetHitBoundary() { return hitBoundary; }
protected:
	float hitBoundary;
	bool arrived;
};

#endif
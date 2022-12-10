#include "supplyBase.h"

SupplyBase::SupplyBase() {
	positionY = 0;
	srand(time(nullptr));
	positionX = rand() % 14 + 1;
	speed = 1;
	hitBoundary = 15.0;
	arrived = false;
}

void SupplyBase::Move() { // TODO: reflect after hitting wall
	positionY += speed / squareSize;
	if(arrived)
		return;
	Update();
}

void SupplyBase::SetArrived(bool a) {
	arrived = a;
}
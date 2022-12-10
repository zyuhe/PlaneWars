#include "supplier.h"

Supplier::Supplier() {
	countH = 0;
	createInterval = 4000; // test
	health = nullptr;
	magazine = nullptr;
	srand(time(nullptr));
}

// 2~4 health, 1 magazine
void Supplier::createSupply() {
	while(createInterval-- == 0) {
		if (countH <= 2) {
			health = new Health();
			countH++;
		} else {
			int select = rand() % 2;
			if(countH > 4 || select == 0) {
				magazine = new Magazine();
				countH = 0;
			} 
			else if (select == 0) {
				countH++;
				health = new Health();
			}
		}

		createInterval = 4000;
	}
	if (health != nullptr) {
		health->Move();
		if (health->GetY() >= 20) {
			health = nullptr;
		}
	}
	
	if (magazine != nullptr) {
		magazine->Move();
		if (magazine->GetY() >= 20) {
			magazine = nullptr;
		}

	}
}
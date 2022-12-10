#include "enemy.h"

Enemy::Enemy() {
	positionY = 0;
	srand(time(nullptr));
	positionX = rand() % 14 + 1;
	speed = 1;
	angle = 0;
	health = 5;
	hitBoundary = 15;
}

Enemy::Enemy(int a) {
	angle = a;
}

void Enemy::Update() {
	int R = hitBoundary;
	float driftX = positionX*squareSize;
	float driftY = positionY*squareSize;

	glBegin(GL_POLYGON);
	glColor3f(153.0/255, 80.0/255, 84.0/255);
	glVertex2f(R + driftX, -R/3 + driftY);
	glVertex2f(-R + driftX, -R/3 + driftY);
	glVertex2f(driftX, R + driftY);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(217.0/255, 104.0/255, 49.0/255);
	glVertex2f(R/3 + driftX, -R/3 + driftY);
	glVertex2f(-R/3 + driftX, -R/3 + driftY);
	glVertex2f(-R/3 + driftX, 4/5 * R + driftY);
	glVertex2f(-R/10 + driftX, R + driftY);
	glVertex2f(R/10 + driftX, R + driftY);
	glVertex2f(R/3 + driftX, 4/5 * R + driftY);
	glEnd();
}

void Enemy::Move() { // TODO: Add reflect function while angle set.
	positionY += speed / squareSize;
	if (health <= 0)
		return;
	Update();
}

void Enemy::ReduceHP(int aggresivity) {
	if (health >= 0)
		health -= aggresivity;
}
#include "player.h"

Player::Player() {
	speed = 3;
	// temporarily write like this
	positionX = 8;
	positionY = 19.4;
	shootInterval = 15;
	score = 0;
	health = 30;
	hitBoundary = 25;
	bulletSize = 32;
	advanced = false;
}

Player::Player(float x, float y) {
	positionX = x;
	positionY = y;
	speed = 3;
}

// draw player's plane
void Player::Update() {
	int R = 30;
	float driftX = positionX*squareSize;
	float driftY = positionY*squareSize;

	glBegin(GL_POLYGON);
	glColor3f(87.0/255, 105.0/255, 60.0/255);
	glVertex2f(R + driftX, R + driftY);
	glVertex2f(-R + driftX, R + driftY);
	glVertex2f(driftX, -R/3 + driftY);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(82.0/255, 75.0/255, 46.0/255);
	glVertex2f(R/3 + driftX, R + driftY);
	glVertex2f(-R/3 + driftX, R + driftY);
	glVertex2f(-R/3 + driftX, -4/5 * R + driftY);
	glVertex2f(-R/10 + driftX, -R + driftY);
	glVertex2f(R/10 + driftX, -R + driftY);
	glVertex2f(R/3 + driftX, -4/5 * R + driftY);
	glEnd();
}

void Player::Move(bool *keyStates) {
	if (keyStates['a']) {
		if (positionX >=0.6)
			positionX -= speed / squareSize;
	}
	if (keyStates['d']) {
		if (positionX <= 15.4)
			positionX += speed / squareSize;
	}
	if (keyStates['w']) {
		if (positionY >= 0.6)
			positionY -= speed / squareSize;
	}
	if (keyStates['s']) {
		if (positionY <= 19.4)
			positionY += speed / squareSize;
	}
	Update();
	shoot();
}

void Player::ReduceHP(int hp) {
	if (health > 0 && health < 100) {
		health -= hp;

		if (hp > 0)
			advanced = false;
	} else if (health == 100 && hp > 0) {
		health -= hp;
	}
}

void Player::updateScore(int s) {
	score += s;
}

// create bullets
void Player::shoot() {
	while(shootInterval-- == 0){
		bullets.emplace_back(BulletBase(positionX, positionY - 0.6, advanced));
		
		shootInterval = 15;
	}
	for (auto& bu : bullets){ // 这里不加&就发射不了。
		bu.Move();
		if ((int)bullets.size() > bulletSize){
			bullets.pop_front();
		}
	}
}

void Player::SetAdvance(bool a) {
	advanced = a;
}

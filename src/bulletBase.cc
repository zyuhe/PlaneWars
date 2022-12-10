#include "bulletBase.h"

BulletBase::BulletBase(float x, float y, bool ad) {
	positionX = x;
	positionY = y;
	aggressivity = 10;
	speed = 2;
	// squareSize = 50.0;
	hit = false;
	hitBoundary = 4;
	advanced = ad;
}

// draw bullet: 2 level
void BulletBase::Update() {
	float driftX = positionX*squareSize;
	float driftY = positionY*squareSize;
	glBegin(GL_POLYGON);
	glColor3f(204.0/255, 202.0/255, 169.0/255);
	glVertex2f(4 + driftX, 7 + driftY);
	glVertex2f(-4 + driftX, 7 + driftY);
	glVertex2f(-4 + driftX, -5 + driftY);
	glVertex2f(-1 + driftX, -7 + driftY);
	glVertex2f(1 + driftX, -7 + driftY);
	glVertex2f(4 + driftX, -5 + driftY);
	glEnd();
	if (advanced) {
		glBegin(GL_POLYGON);
		glVertex2f(-7 + driftX, 7 + driftY);
		glVertex2f(-15 + driftX, 7 + driftY);
		glVertex2f(-15 + driftX, -5 + driftY);
		glVertex2f(-12 + driftX, -7 + driftY);
		glVertex2f(-10 + driftX, -7 + driftY);
		glVertex2f(-7 + driftX, -5 + driftY);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(15 + driftX, 7 + driftY);
		glVertex2f(7 + driftX, 7 + driftY);
		glVertex2f(7 + driftX, -5 + driftY);
		glVertex2f(10 + driftX, -7 + driftY);
		glVertex2f(12 + driftX, -7 + driftY);
		glVertex2f(15 + driftX, -5 + driftY);
		glEnd();
		hitBoundary = 13;
	}
}

// bullet can only move vertically up
void BulletBase::Move() {
	positionY -= speed / squareSize;
	if (hit)
		return;
	Update();
}

void BulletBase::SetHit(bool h) {
	hit = h;
}

void BulletBase::upgrade() {
	advanced = true;
}

void BulletBase::degrade() {
	advanced = false;
}
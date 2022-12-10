#include "health.h"

Health::Health() {
	health = 10;
}

// draw a heart
void Health::Update() {
	int R = hitBoundary;
	float driftX = positionX*squareSize;
	float driftY = positionY*squareSize;
	glBegin(GL_POLYGON);
	glColor3f(226.0/255, 17.0/255, 0/255);
	glVertex2f(driftX, -R/3 + driftY);
	glVertex2f(-R/4 + driftX, -R + driftY);
	glVertex2f(-3*R/4 + driftX, -R + driftY);
	glVertex2f(-R + driftX, -R/3 + driftY);
	glVertex2f(-2*R/3 + driftX, R/2 + driftY);
	glVertex2f(driftX, R + driftY);
	glVertex2f(2*R/3 + driftX, R/2 + driftY);
	glVertex2f(R + driftX, -R/3 + driftY);
	glVertex2f(3*R/4 + driftX, -R + driftY);
	glVertex2f(R/4 + driftX, -R + driftY);
	glEnd();
}
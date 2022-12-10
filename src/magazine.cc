#include "magazine.h"

Magazine::Magazine() {
	level = 1;
}

// draw ...
void Magazine::Update() {
	int R = hitBoundary;
	float driftX = positionX*squareSize;
	float driftY = positionY*squareSize;
	glColor3f(253.0/255, 218.0/255, 4.0/255);
	glBegin(GL_POLYGON);
	glVertex2f(driftX, -R + driftY);
	glVertex2f(-R + driftX, -R/3 + driftY);
	glVertex2f(-R + driftX, driftY);
	glVertex2f(driftX, -2*R/3 + driftY);
	glVertex2f(R + driftX, driftY);
	glVertex2f(R + driftX, -R/3 + driftY);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(driftX, driftY);
	glVertex2f(-R + driftX, 2*R/3 + driftY);
	glVertex2f(-R + driftX, R + driftY);
	glVertex2f(driftX, R/3 + driftY);
	glVertex2f(R + driftX, R + driftY);
	glVertex2f(R + driftX, 2*R/3 + driftY);
	glEnd();
}
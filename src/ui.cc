#include "ui.h"
#include <ctime>

void UI::drawRect(int beginX, int beginY, int l, int h) {
	glBegin(GL_POLYGON);
	glVertex2f(beginX, beginY);
	glVertex2f(beginX, beginY + h);
	glVertex2f(beginX + l, beginY + h);
	glVertex2f(beginX + l, beginY);
	glEnd();
}

void UI::drawHeart(int driftX, int driftY) {
	int R = 10;
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

void UI::drawBulletUp(int driftX, int driftY) {
	int R = 15;
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

void UI::drawReturn(int driftX, int driftY) {
	int R = 20;
	glBegin(GL_POLYGON);
	glColor3f(230.0/255, 155.0/255, 3.0/255);
	glVertex2f(-R + driftX, driftY);
	glVertex2f(driftX, -R + driftY);
	glVertex2f(driftX, -R/3 + driftY);
	glVertex2f(R + driftX, -R/3 + driftY);
	glVertex2f(R + driftX, R/3 + driftY);
	glVertex2f(driftX, R/3 + driftY);
	glVertex2f(driftX, R + driftY);
	glEnd();
}

// base of welcome page and result page
void UI::displayBase() {
	glClearColor(18.0/255, 53.0/255, 85.0/255, 1.0);
	glColor3f(200.0/255, 155.0/255, 3.0/255);
	drawRect(200, 300, 400, 200);
	drawRect(300, 550, 200, 50);
	drawRect(300, 630, 200, 50);

	string message;
	string::iterator it;

	glColor3f(1, 1, 1);
	message = "START";
	it = message.begin();
	glRasterPos2f(370, 580);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "HISTORY";
	it = message.begin();
	glRasterPos2f(360, 660);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "Use A to go left, D to go right, W to go up, S to go down.";
	it = message.begin();
	glRasterPos2f(170, 720);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "Get             to increase HP.";
	it = message.begin();
	glRasterPos2f(310, 760);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "Get             to upgrade bullet.";
	it = message.begin();
	glRasterPos2f(310, 800);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);


	// same as health.cc and magazine.cc ...
	drawHeart(373, 753);
	drawBulletUp(373, 793);
	
}

// welcome page
void UI::displayWelcome() {
	displayBase();
	string message;
	string::iterator it;

	message = "Plane Wars";
	it = message.begin();
	glColor3f(1, 1, 1);
	glRasterPos2f(340, 400);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	
	glColor3f(200.0/255, 200.0/255, 200.0/255);
	drawRect(600, 50, 155, 40);
	glColor3f(1, 1, 1);
	message = "Login & Register";
	it = message.begin();
	glRasterPos2f(610, 75);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}

// game on page
void UI::updateGameOn(int HP, int score) {
	glColor3f(1, 1, 1);
	string HP_s = to_string(HP);
	string score_s = to_string(score);
	string message = "Your Score: " + score_s;
	string::iterator it = message.begin();
	glRasterPos2f(40, 40);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "HP: ";
	it = message.begin();
	glRasterPos2f(40, 75);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	int n = HP / 10;
	for (int i = 0; i < n; i++) {
		drawHeart(90 + i * 25, 70);
	}
}

// result page
void UI::displayResult(int score, int winScore) {
	displayBase();
	glColor3f(1, 1, 1);
	string message;
	if (score < winScore){
		message = "Your Score: " + to_string(score);
		glRasterPos2f(330, 400);
	} else {
		message = "You Win !!!";
		glRasterPos2f(350, 400);
	}
	string::iterator it = message.begin();
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
}

void UI::displayHistory(char ** res, int hislen) {
	drawReturn(50, 50);
	string message;
	string::iterator it;

	glColor3f(1, 1, 1);
	message = "SCORE HISTORY(best 10)";
	it = message.begin();
	glRasterPos2f(285, 100);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	glColor3f(200.0/255, 175.0/255, 3.0/255);
	drawRect(175, 130, 450, 50);
	glColor3f(1, 1, 1);
	message = "TIME                                  SCORE";
	it = message.begin();
	glRasterPos2f(260, 160);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	time_t c;
	struct tm tm;
	char s[40];
	string update_time;
	if(hislen > 10)
		hislen = 10;
	for (int i = 0; i < hislen; i++){
		glColor3f(200.0/255, 155.0/255, 3.0/255);
		drawRect(175, 200 + i*50, 450, 35);
		glColor3f(1, 1, 1);
		update_time = res[3*(i+1) + 1];
		c = (time_t)(atoi(update_time.c_str()));
		
		tm = *std::localtime(&c);
		strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
		message = s;
		it = message.begin();
		glRasterPos2f(200, 225 + i*50);
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
		message = res[3*(i+1) + 2];
		it = message.begin();
		glRasterPos2f(500, 225 + i*50);
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}
}

void UI::displayLogin() {
	// TODO
}

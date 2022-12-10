#ifndef _UI_H_
#define _UI_H_

#include <cstring>
#include <GL/glut.h>
#include <iterator>

using namespace std;

class UI {
public:
	UI() {}
	void drawRect(int, int, int, int);
	void drawHeart(int, int);
	void drawBulletUp(int, int);
	void drawReturn(int, int);
	void displayBase();
	void displayWelcome();
	void updateGameOn(int HP, int score);
	void displayResult(int score, int winScore);
	void displayHistory(char**, int);
	void displayLogin();
private:
};

#endif
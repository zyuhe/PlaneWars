#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "common.h"
#include "tools.h"
#include "string.h"
#include "DBController.h"
#include <iostream>
#include <sqlite3.h>

using namespace std;

void display();
void reshape(int width, int height);

void keyPressed(unsigned char key, int x, int y);
void KeyUp(unsigned char key, int x, int y);
void mousePressed(int button, int state, int x, int y);

void init();
void judgeAttack();
void controlPlayer();
void createEnemy();
void createSupply();
void updateUI();
void judgeGameover();

#endif
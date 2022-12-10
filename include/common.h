#ifndef _COMMON_H_
#define _COMMON_H_

#include <GL/glut.h>
#include "enemyController.h"
#include "supplier.h"
#include "player.h"
#include "bulletBase.h"
#include "ui.h"

extern bool welcomed;
extern bool gameover;
extern bool onShowHistory;
extern bool scoreUpdated;
extern char** res;
extern int hislen;
extern int winScore;
extern UI* ui;
extern EnemyController* ectl;
extern Supplier* supplier;
extern Player* player;

extern bool* keyStates; // key record

#endif
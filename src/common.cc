#include "common.h"

bool welcomed = false;
bool gameover = false;
bool onShowHistory = false;
bool scoreUpdated = false;
int winScore = 1000;
char** res;
int hislen = 0;

UI* ui = new UI();
EnemyController* ectl = new EnemyController();
Supplier* supplier = new Supplier();
Player* player = new Player();

bool* keyStates = new bool[256];
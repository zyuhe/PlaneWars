#include "controller.h"
#include "ui.h"

void reshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glOrtho(0, windowSizeX, windowSizeY, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);
	// gameOver();
	if (welcomed) {
		if (!gameover) {
			updateUI();
			judgeAttack();
			controlPlayer();
			createEnemy();
			createSupply();
			judgeGameover();
		} else {
			if (!scoreUpdated){
				updateScore(player->GetScore());
				res = searchBest10();
				hislen = searchLength();
				scoreUpdated = true;
			}
			
			if (onShowHistory)
				ui->displayHistory(res, hislen);
			else
				ui->displayResult(player->GetScore(), winScore);
		}
	} else {
		if (onShowHistory)
			ui->displayHistory(res, hislen);
		else{

			ui->displayWelcome();
		}
	}
	glutSwapBuffers();
}

// judge bullet attack enemy
void judgeAttack() {
	for (auto& bu : player->GetBullets()) {
		for (auto& e : ectl->GetEnemys()) {
			if (!bu.GetHit() && e.GetHealth() > 0){
				float distance = sqrt((bu.GetX() - e.GetX())*(bu.GetX() - e.GetX()) + (bu.GetY() - e.GetY())*(bu.GetY() - e.GetY()));
				if (distance <= (e.GetHitBoundary() + bu.GetHitBoundary()) / squareSize) {
					e.ReduceHP(bu.GetAggressivity());
					bu.SetHit(true);
					player->updateScore(1);
				}
			}
			
		}
	}
}

// move plane, judge hit by enemy, get heart, get magazine
void controlPlayer() {
	// ui->showHP(player->GetHealth());
	player->Move(keyStates);
	float distance;
	for (auto& e : ectl->GetEnemys()) {
		if (e.GetHealth() > 0) {
			distance = sqrt((player->GetX() - e.GetX())*(player->GetX() - e.GetX()) + (player->GetY() - e.GetY())*(player->GetY() - e.GetY()));
			if (distance <= (e.GetHitBoundary() + player->GetHitBoundary()) / squareSize) {
				player->ReduceHP(10);
				e.ReduceHP(100);
			}
		}
	}
	Health *temp = supplier->GetHealth();
	if (temp != nullptr) {
		distance = sqrt((player->GetX()-temp->GetX()) * (player->GetX()-temp->GetX()) + (player->GetY()-temp->GetY()) * (player->GetY()-temp->GetY()));
		if (distance <= (player->GetHitBoundary() + temp->GetHitBoundary()) / squareSize && !temp->GetArrived()) {
			player->ReduceHP(-temp->GetHealth());
			temp->SetArrived(true);
		}
	}
	Magazine *temp2 = supplier->GetMagazine();
	if (temp2 != nullptr) {
		distance = sqrt((player->GetX()-temp2->GetX()) * (player->GetX()-temp2->GetX()) + (player->GetY()-temp2->GetY()) * (player->GetY()-temp2->GetY()));
		if (distance <= (player->GetHitBoundary() + temp2->GetHitBoundary()) / squareSize && !temp2->GetArrived()) {
			player->SetAdvance(true);
			temp2->SetArrived(true);
		}
	}
}

void createEnemy() {
	ectl->Create();
}

// heart or magazine
void createSupply() {
	supplier->createSupply();
}

// draw game information
void updateUI() {
	ui->updateGameOn(player->GetHealth(), player->GetScore());
}

// lose or win result
void judgeGameover() {
	if (player->GetHealth() <= 0 || player->GetScore() == winScore) {
		gameover = true;
	}
}

//key pressed
void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true;
}

//key free
void KeyUp(unsigned char key, int x, int y) {
	keyStates[key] = false;
}

void mousePressed(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN){
			if(x >= 300 && x <= 500 && y >= 550 && y <= 600) {
				if (!welcomed && !onShowHistory)
					welcomed = true;
				else if(welcomed && gameover && !onShowHistory){
					resetGame();
					gameover = false;
				}
			}
			if(x >= 300 && x <= 500 && y >= 630 && y <= 680) {
				if(!welcomed || (welcomed && gameover)) {
					onShowHistory = true;
				}
			}
			if(x >= 30 && x <= 70 && y >= 30 && y <= 70) {
				if(onShowHistory) {
					onShowHistory = false;
				}
			}
		}
	}
}
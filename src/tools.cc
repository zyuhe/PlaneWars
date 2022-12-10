#include "tools.h"

// record key pressed
void keyOperations() {
	// if (keyStates[' ']) {
	// 	if (!welcomed) {
	// 		welcomed = true;
	// 	}
	// 	if (welcomed && gameover) {
	// 		resetGame();
	// 		gameover = false;
	// 	}
	// }
}

// reset game
void resetGame() {
	player = new Player();
	ui = new UI();
	ectl = new EnemyController();
	supplier = new Supplier();
	scoreUpdated = false;
}
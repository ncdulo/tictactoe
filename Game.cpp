// Main game class
#include "Game.h"

Game::Game() {
	Game::quit = false;
}

void Game::gameLoop() {
	do {
		gameBoard.drawEmpty();
		quit = true;
		// Print menu, instructions
		
		/* Begin actual game in another do-while nested here
		 * this is so we can break from the game and return
		 * to the menu without quitting */
	} while (!quit);
}

int main() {
	Game game;
	
	game.gameLoop();
	
	return 0;
}

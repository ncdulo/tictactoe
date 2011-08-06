// Main game class
#include "Game.h"
#include <iostream>
using namespace std;

void Game::gameLoop() {
	do {
		printMenu();
		
		printInstructions();
		
		bool playerFirst = playerSelect();
		isDraw = false;
		gameOver = false;
		numberTurns = 0;
		
		do {
			gameBoard.draw(true);
			
			if(playerFirst) {
				playerTurn();
				if(checkWin() == 'c')
					continue;
				computerTurn();
			} else {
				computerTurn();
				if(checkWin() == 'c');
					continue;
				playerTurn();
			}
			numberTurns++;
		} while(!gameOver);
		
		// Ask to play again
		quit = true;
	} while (!quit);
}

void Game::printMenu() {
	cout << endl;
	cout << "Welcome to TicTacToe!" << endl;
	printSeperator();
	cout << "Programmed by Nick Cardullo" << endl;
	cout << "     Email:  <nick.cardullo@gmail.com>" << endl;
	printSeperator();
}

void Game::printInstructions() {
	cout << "Instructions:" <<endl;
	printSeperator();
	cout << " Once you begin, you will see a numbered" << endl;
	cout << " grid. On your turn enter the number of" << endl;
	cout << " the square you would like to mark and" << endl;
	cout << " then press enter. Repeat until there are" << endl;
	cout << " no more empty squares left, or until a" << endl;
	cout << " winner is found!" << endl;
	printSeperator();
	cout << "Winning Moves:" << endl;
	printSeperator();
	cout << " You may win by forming a line of three" << endl;
	cout << " of your mark either horizantally, vertically" << endl;
	cout << " or diagonally." << endl;
	printSeperator();
	cout << "               GOOD LUCK!" << endl;                         
	printSeperator();
	
}

void Game::printSeperator() {
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl; 
}

bool Game::playerSelect() {
	char input;		// Temporary storage for user input
	bool done = false;
	
	do {
		cout << "Will you go first?" << endl;
		cin >> input;

		if((input == 'y') || (input == 'n')) 
			done = true;
	} while(!done);
	
	// We return true if the player is first, false otherwise	
	if(input == 'y') {
		player = 'x';
		computer = 'o';
		return true;
	} else {
		player = 'o';
		computer = 'x';
		return false;
	}
}

void Game::playerTurn() {
	int y, x;
	bool done = false;
	
	do {
		cout << "Player enter the coordinates for your move, seperated by a space, vertical first" << endl;
		cin >> y >> x;
		
		if(gameBoard.markBoard(y, x, player))
			done = true;
	} while(!done);
}

void Game::computerTurn() {
	/* Basic AI to be implemented:
	 * Computer will first try center - 2,2
	 * Next we will go above player - playerY-1,playerX
	 * Next we try below - playerY+1,playerX
	 * Next we try the left - playerY,playerX-1
	 * Finally we go for whats right - playerY,playerX+1
	 */
	cout << "computer turn" << endl;
}


// Checks the board for any win/lose conditions
// returns 'c' - continue, 'd' - draw
// or if winner then returns 'x' or 'o'
char Game::checkWin() {
	if(numberTurns > 9) {
		// Draw, end game
		gameOver = true;
		isDraw = true;
		return true;
	} else {
		// Game in progress, check for winner
		
		// Horizontal Win Checks
		for(int y = 0; y < 3; y++) {
			if((gameBoard.getMark(y,0) != ' ') && (gameBoard.getMark(y,0) == gameBoard.getMark(y,1) && (gameBoard.getMark(y,0) == gameBoard.getMark(y,2)))) {
				gameOver = true;
				isDraw = false;
				return gameBoard.getMark(y,0);
			}
		}
		// Vertical Win Checks
		for(int x = 0; x < 3; x++) {
			if((gameBoard.getMark(0,x) != ' ') && (gameBoard.getMark(0,x) == gameBoard.getMark(1,x) && (gameBoard.getMark(0,x) == gameBoard.getMark(2,x)))) {
				gameOver = true;
				isDraw = false;
				return gameBoard.getMark(0,x);
			}
		}
		// Diagonal Win Checks
		if((gameBoard.getMark(0,0) != ' ') && (gameBoard.getMark(0,0) == gameBoard.getMark(1,1) && (gameBoard.getMark(0,0) == gameBoard.getMark(2,2)))) {
			gameOver = true;
			isDraw = false;
			return gameBoard.getMark(0,0);
		}
		if((gameBoard.getMark(0,2) != ' ') && (gameBoard.getMark(0,0) == gameBoard.getMark(1,1) && (gameBoard.getMark(0,2) == gameBoard.getMark(2,0)))) {
			gameOver = true;
			isDraw = false;
			return gameBoard.getMark(0,2);
		}
	}
	
	return false;
}

int main() {
	Game game;
	
	game.gameLoop();
	
	return 0;
}

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
				if(checkWin())
					continue;
				computerTurn();
			} else {
				computerTurn();
				if(checkWin());
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
	cout << "computer" << endl;
}

bool Game::checkWin() {
	if(numberTurns > 9) {
		gameOver = true;
		isDraw = true;
		return true;
	}
	
	return false;
}

int main() {
	Game game;
	
	game.gameLoop();
	
	return 0;
}

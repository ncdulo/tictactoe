// Main game class
#include "Game.h"
#include "config.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void Game::gameLoop() {
	printMenu();
	printInstructions();
	do {
		resetGame();
		gameBoard.resetBoard();
		
		do {
			gameBoard.draw(true);
			if(player == 'x') {
				playerTurn();
				computerTurn();
			} else {
				computerTurn();
				gameBoard.draw(true);
				playerTurn();
			}
		} while(!gameOver);
		
		if(askWinner())
			quit = false;
		else
			quit = true;
	} while (!quit);
}

void Game::resetGame() {
	isDraw = false;
	gameOver = false;
	winner = ' ';
	numberTurns = 0;
	
	playerSelect();
}

void Game::printMenu() {
	cout << endl;
	cout << "Welcome to "  << PACKAGE_STRING << "!" << endl;
	printSeperator();
	cout << "Send bug reports to " << PACKAGE_BUGREPORT << endl;
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

bool Game::askWinner() {
	// Print a win message
	printSeperator();
	if(isDraw)
		cout << "             Y U NO WIN!?" << endl;
	else if(winner == player)
		cout << "          A WINNER IS YOU!" << endl;
	else
		cout << "           COMPUTER WINS!" << endl;
	printSeperator();
	
	
	// Figure out if we are going to play again
	bool done = false;
	char input;
	do {
		cout << "Would you like to play again?" << endl;
		cin >> input;
		if(input == 'y')
			return true;
		else if(input == 'n')
			return false;
	} while (!done);
	
	return false;
}

void Game::playerTurn() {
	if(checkWin())
		return;
		
	int y, x;
	bool done = false;
	
	do {
		cout << "Player enter the coordinates for your move, seperated by a space, vertical first" << endl;
		cin >> y >> x;
		
		if(gameBoard.markBoard(y-1, x-1, player))
			done = true;
	} while(!done);
}

void Game::computerTurn() {
	if(checkWin())
		return;
	// For now we use a dumb AI (randomly moves)
	// until I can figure out a MiniMax implementation
	srand((unsigned)time(0));
	bool done = false;
	do {
		int y = rand()%3;
		int x = rand()%3;
		if(gameBoard.markBoard(y, x, computer))
			done = true;
			
		//cout << y << " " << x << endl;
	} while(!done);
}


// Checks the board for any win/lose conditions
// True if there is a winner or draw, false otherwise
bool Game::checkWin() {
	if(numberTurns >= 9) {
		// Draw, end game
		gameOver = true;
		isDraw = true;
		winner = ' ';
		return true;
	} else {
		// Game in progress, check for winner
		
		// Horizontal Win Checks
		for(int y = 0; y < 3; y++) {
			if((gameBoard.getMark(y,0) != ' ') && (gameBoard.getMark(y,0) == gameBoard.getMark(y,1) && (gameBoard.getMark(y,0) == gameBoard.getMark(y,2)))) {
				gameOver = true;
				isDraw = false;
				winner = gameBoard.getMark(y,0);
				numberTurns++;
				return true;
			}
		}
		// Vertical Win Checks
		for(int x = 0; x < 3; x++) {
			if((gameBoard.getMark(0,x) != ' ') && (gameBoard.getMark(0,x) == gameBoard.getMark(1,x) && (gameBoard.getMark(0,x) == gameBoard.getMark(2,x)))) {
				gameOver = true;
				isDraw = false;
				winner = gameBoard.getMark(0,x);
				numberTurns++;
				return true;
			}
		}
		// Diagonal Win Checks
		if((gameBoard.getMark(0,0) != ' ') && (gameBoard.getMark(0,0) == gameBoard.getMark(1,1) && (gameBoard.getMark(0,0) == gameBoard.getMark(2,2)))) {
			gameOver = true;
			isDraw = false;
			winner = gameBoard.getMark(0,0);
			numberTurns++;
			return true;
		}
		if((gameBoard.getMark(0,2) != ' ') && (gameBoard.getMark(0,0) == gameBoard.getMark(1,1) && (gameBoard.getMark(0,2) == gameBoard.getMark(2,0)))) {
			gameOver = true;
			isDraw = false;
			winner = gameBoard.getMark(0,2);
			numberTurns++;
			return true;
		}
	}
	
	return false;
}

int main() {
	Game game;
	
	game.gameLoop();
	
	return 0;
}

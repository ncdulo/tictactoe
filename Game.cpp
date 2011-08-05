// Main game class
#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
	Game::quit = false;
}

void Game::gameLoop() {
	do {
		printMenu();
		
		printInstructions();
		
		quit = true;
		
		/* Begin actual game in another do-while nested here
		 * this is so we can break from the game and return
		 * to the menu without quitting */
	} while (!quit);
}

void Game::printMenu() {
	cout << endl;
	cout << "Welcome to TicTacToe!" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Programmed by Nick Cardullo" << endl;
	cout << "     Email:  <nick.cardullo@gmail.com>" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
}

void Game::printInstructions() {
	cout << "Instructions:" <<endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	cout << " Once you begin, you will see a numbered" << endl;
	cout << " grid. On your turn enter the number of" << endl;
	cout << " the square you would like to mark and" << endl;
	cout << " then press enter. Repeat until there are" << endl;
	cout << " no more empty squares left, or until a" << endl;
	cout << " winner is found!" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Winning Moves:" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	cout << " You may win by forming a line of three" << endl;
	cout << " of your mark either horizantally, vertically" << endl;
	cout << " or diagonally." << endl;
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "               GOOD LUCK!" << endl;                         
	cout << "- - - - - - - - - - - - - - - - - - - -" << endl; 
	
}
int main() {
	Game game;
	
	game.gameLoop();
	
	return 0;
}

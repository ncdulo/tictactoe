// Main game class
#include "GameBoard.h"

class Game {
	public:
		Game();
		void gameLoop();
		
	private:
		bool 		quit;			// True - quiut, False - contine
		GameBoard 	gameBoard;		// Stores the board for the game
		char		player;			// Each player represented by
		char		computer;		// a char of either 'x' or 'o'.
		
		void printMenu();
		void printInstructions();
		void playerSelect();
		
	protected:
		void printSeperator();		// A simple horizontal seperator
};

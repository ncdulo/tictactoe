// Main game class
#include "GameBoard.h"

class Game {
	public:
		void gameLoop();
		
	private:
		bool 		quit;
		bool		gameOver;		// == true when checkWin() returns true
		bool		isDraw;			// == true when the game is draw, false otherwise
		GameBoard 	gameBoard;		// Stores the board for the game
		char		player;			// Each player represented by
		char		computer;		// a char of either 'x' or 'o'.
		int			numberTurns;	// To track when we get a draw
		
		void printMenu();
		void printInstructions();
		bool playerSelect();		// True if player goes first, false otherwise
		
		void playerTurn();
		void computerTurn();
		
		bool checkWin();			// True if win, false otherwise
		
	protected:
		void printSeperator();		// A simple horizontal seperator
};

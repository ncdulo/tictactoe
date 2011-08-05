// Main game class
#include "GameBoard.h"

class Game {
	public:
		Game();
		void gameLoop();
		
	private:
		bool quit;
		GameBoard gameBoard;
};

// GameBoard
// This class will draw a TicTacToe board
using namespace std;

class GameBoard {
	public:
		GameBoard();
		void draw(bool withMarks);
		bool markBoard(int y, int x, char mark);
		char getMark(int y, int x);
		void resetBoard();
		
	private:
		char boardState[3][3];	// Array of marks on the board. [Vert][Horiz]
		void drawRow();
};

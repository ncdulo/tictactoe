// GameBoard
// This class will draw a TicTacToe board
#include <vector>
using namespace std;

class GameBoard {
	public:
		void drawEmpty();
		void drawWithMarks(vector<int> X, vector<int> O);
		
	private:
		void drawRow();
		void drawMiddleRow();
};

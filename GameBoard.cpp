// GameBoard
// This class will draw a TicTacToe game board
#include "GameBoard.h"
#include <vector>
#include <iostream>
using namespace std;

void GameBoard::drawEmpty() {
	GameBoard::drawRow();		// Draw the top row now
	for(int i = 0; i < 3; i++) {
		GameBoard::drawMiddleRow();
		GameBoard::drawRow();
	}
}

void GameBoard::drawWithMarks(vector<int> X, vector<int> O) {

}

void GameBoard::drawRow() {
	cout << "  +---+---+---+" << endl;
	
}

void GameBoard::drawMiddleRow() {
	cout << "  |   |   |   |" << endl;
}

int main() {
	GameBoard gb;
	gb.drawEmpty();
	return 0;
}

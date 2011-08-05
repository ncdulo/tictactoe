// GameBoard
// This class will draw a TicTacToe game board
#include "GameBoard.h"
#include <vector>
#include <iostream>
using namespace std;

// Draw an empty row on the game board
void GameBoard::drawEmpty() {
	GameBoard::drawRow();		// Draw the top row now, everything else loops
	for(int i = 0; i < 3; i++) {
		GameBoard::drawMiddleRow();
		GameBoard::drawRow();
	}
}

// TODO: Figure out the best way to implement and make it happen
void GameBoard::drawWithMarks(vector<int> X, vector<int> O) {

}

// Draw a single, solid row on the board
void GameBoard::drawRow() {
	cout << "  +---+---+---+" << endl;
	
}

// Draw a row with blanks for players to mark
void GameBoard::drawMiddleRow() {
	cout << "  |   |   |   |" << endl;
}

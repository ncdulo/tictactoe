// GameBoard
// This class will draw a TicTacToe game board
#include "GameBoard.h"
#include <vector>
#include <iostream>
using namespace std;

GameBoard::GameBoard() {
	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 3; x++) {
			boardState[y][x] = ' ';
		}
	}
}

// Draw an empty row on the game board
void GameBoard::draw(bool withMarks) {
	cout << "     1   2   3" << endl;
	drawRow();		// Draw the top row now, everything else loops
	for(int y = 0; y < 3; y++) {
		if(!withMarks) {
			cout << "   |   |   |   |" << endl;
		} else {
			//for(int x = 0; x < 3; x++)
			cout << " " << y + 1 << " | " << boardState[y][0] << " | " << boardState[y][1] << " | " << boardState[y][2] << " |" << endl;
		}
		drawRow();
	}
}

// Draw a single, solid row on the board
void GameBoard::drawRow() {
	cout << "   +---+---+---+" << endl;
	
}

// Place a mark at y, x. Returns true if success, false otherwise
bool GameBoard::markBoard(int y, int x, char mark) {
	// Remember, arrays begin at 0 so we subtract 1 to even things out
	y--;
	x--;
	
	if(y < 3 && x < 3) {
		boardState[y][x] = mark;
		return true;
	} else {
		return false;
	}
}

// Return the char from a specific spot on the board
char GameBoard::getMark(int y, int x) {
	return boardState[y][x];
}

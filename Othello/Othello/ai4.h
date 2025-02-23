#pragma once
#include <vector>
#include <utility>
class ai4
{
public:
	bool inBoard(int x, int y);
	bool isValidMove(char board[8][8], char player, int row, int col);
	std::vector<std::pair<int, int>> getValidMoves(char board[8][8], char player);
	void copyBoard(char srcBoard[8][8], char destBoard[8][8]);
	void makeMove(char board[8][8], char player, int row, int col);
	int evaluateBoard(char board[8][8], char player);
	int alphaBetaSearch(char board[8][8], char player, int depth, int alpha, int beta);
	std::pair<int, int> ai(char board[8][8], char player);
	int countValidMoves(char board[8][8], char player);
	int countStablePieces(char board[8][8], char player);
	int countConnectedRegions(char board[8][8], char player);


};
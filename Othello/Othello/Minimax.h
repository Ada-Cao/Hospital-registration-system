#pragma once
#include<utility>
#include<vector>
using namespace std;

class Minimax
{
public:
	bool isOnBoard(int x, int y);
	vector<std::pair<int, int>> isValid(char board[8][8], char player, int row, int col);
	vector<std::pair<int, int>> validMoves(char board[8][8], char player);
	std::pair<int, int> max(char board[8][8], int depth, int alpha, int beta, char player, int hard);
	std::pair<int, int> min(char board[8][8], int depth, int alpha, int beta, char player, int hard);
	int evaluate(char board[8][8], int hard);
	int getStability(char board[8][8], std::pair<int, int> p);
	//std::pair<int, int>getMove(char board[8][8], char player);
};






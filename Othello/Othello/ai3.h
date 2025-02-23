#pragma once
#include<utility>
class ai3
{
public:
	bool inBoard(int x, int y);
	int countValidMoves(char board[8][8], char player);
	int countStablePieces(char board[8][8], char player);
	int countConnectedRegions(char board[8][8], char player);
	std::pair<int, int> ai(char board[8][8], char player);	//aiÂä×Ó
};


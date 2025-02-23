#pragma once
#include<utility>
class ai2
{
public:
	bool inBoard(int x, int y);
	int countValidMoves(char board[8][8], char player);
	int countCornerControl(char board[8][8], char player);
	std::pair<int, int> ai(char board[8][8], char player);	//aiÂä×Ó
};


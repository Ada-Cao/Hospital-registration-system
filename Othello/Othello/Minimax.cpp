#include "Minimax.h"
#include<iostream>

//判断是否在棋盘范围内
bool Minimax::isOnBoard(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		return true;
	}
	return false;
}

vector<std::pair<int, int>> Minimax::isValid(char board[8][8], char player, int row, int col)
{
	vector<std::pair<int, int>> ToFlip;
	if (isOnBoard(row, col) == false || board[row][col] != ' ')
	{
		return ToFlip;
	}
	char opponent;
	board[row][col] = player;

	if (player == 'B')
	{
		opponent = 'W';
	}
	else if (player == 'W')
	{
		opponent = 'B';
	}

	int Direction[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
	for (int i = 0; i < 8; ++i)
	{
		int x = row;
		int y = col;
		int xdirection = Direction[i][0];
		int ydirection = Direction[i][1];
		x += xdirection;
		y += ydirection;
		if (isOnBoard(x, y) && board[x][y] == opponent)
		{
			x += xdirection;
			y += ydirection;
			if (isOnBoard(x, y) == false)
			{
				continue;
			}

			while (board[x][y] == opponent)
			{
				x += xdirection;
				y += ydirection;
				if (isOnBoard(x, y) == false)
				{
					break;
				}
			}

			if (isOnBoard(x, y) == false)
			{
				continue;
			}

			if (board[x][y] == player)
			{
				while (true)
				{
					x -= xdirection;
					y -= ydirection;
					if (x == row && y == col)
					{
						break;
					}
					ToFlip.push_back({ x,y });
				}
			}
		}
	}
	board[row][col] = ' ';
	return ToFlip;
}

//存储合法落子位置  getMove()
vector<std::pair<int, int>> Minimax::validMoves(char board[8][8], char player)
{
	vector<std::pair<int, int>> validMoves;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (isValid(board, player, i, j).size() != 0)
			{
				validMoves.push_back({ i,j });
			}
		}
	}
	return validMoves;

}

//MAX函数
std::pair<int, int> Minimax::max(char board[8][8], int depth, int alpha, int beta, char player, int hard)
{
	int bestV = -10000;
	char nboard[8][8];
	std::pair<int, int> move;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			nboard[i][j] = board[i][j];
		}
	}

	vector<std::pair<int, int>> valids = validMoves(board, player);

	if (depth == 0)
	{
		bool flag = false;

		for (int i = 0; i < valids.size(); ++i)
		{
			flag = true;
			nboard[valids[i].first][valids[i].second] = player;
			if (evaluate(nboard, hard) > bestV)
			{
				bestV = evaluate(nboard, hard);
				move = valids[i];
			}
			nboard[valids[i].first][valids[i].second] = ' ';
		}

		if (flag)
		{
			return move;
		}
		else
		{
			return { -1,-1 };
		}

	}

	if (valids.size() == 0)
	{
		return { -1,-1 };
	}

	for (int i = 0; i < valids.size(); ++i)
	{
		alpha = bestV > alpha ? bestV : alpha;
		if (alpha >= beta)
		{
			break;
		}
		nboard[valids[i].first][valids[i].second] = player;
		std::pair<int, int> next;

		char opponent;
		if (player == 'B')
		{
			opponent = 'W';
		}
		else if (player == 'W')
		{
			opponent = 'B';
		}
		next = min(nboard, depth - 1, alpha, beta, opponent, hard);
		nboard[next.first][next.second] = opponent;
		int value = evaluate(nboard, hard);
		if (value < bestV)
		{
			bestV = value;
			move = valids[i];
		}
		nboard[next.first][next.second] = ' ';
		nboard[valids[i].first][valids[i].second] = ' ';
	}

	//cout << "我运行了！" << endl;
	return move;

}

//Min函数
std::pair<int, int>  Minimax::min(char board[8][8], int depth, int alpha, int beta, char player, int hard)
{
	int bestV = 10000;
	char nboard[8][8];
	std::pair<int, int> move;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			nboard[i][j] = board[i][j];
		}
	}

	vector<std::pair<int, int>> valids = validMoves(board, player);
	if (depth == 0)
	{
		bool flag = false;
		for (int i = 0; i < valids.size(); ++i)
		{
			flag = true;
			nboard[valids[i].first][valids[i].second] = player;
			if (evaluate(nboard, hard) < bestV)
			{
				bestV = evaluate(nboard, hard);
				move = valids[i];
			}
			nboard[valids[i].first][valids[i].second] = ' ';
		}

		if (flag)
		{
			return move;
		}
		else
		{
			return { -1,-1 };
		}
	}

	for (int i = 0; i < valids.size(); ++i)
	{
		beta = bestV < beta ? bestV : beta;
		if (alpha >= beta)
		{
			break;
		}
		std::pair<int, int> next;

		char opponent;
		if (player == 'B')
		{
			opponent = 'W';
		}
		else if (player == 'W')
		{
			opponent = 'B';
		}
		next = max(nboard, depth - 1, alpha, beta, opponent, hard);
		nboard[valids[i].first][valids[i].second] = player;
		nboard[next.first][next.second] = opponent;
		int value = evaluate(nboard, hard);
		if (value < bestV)
		{
			bestV = value;
			move = valids[i];
		}
		nboard[next.first][next.second] = ' ';
		nboard[valids[i].first][valids[i].second] = ' ';

	}

	return move;
}


int Minimax::evaluate(char board[8][8], int hard)
{
	int whiteEvaluate = 0;
	int blackEvaluate = 0;
	vector<std::pair<int, int>> b, w;
	int sb, sw;
	int weight[5] = { 2,4,6,10,15 };
	switch (hard)
	{
	case 1:
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (board[i][j] == 'W')
				{
					whiteEvaluate += 1;
				}
				else if (board[i][j] == 'B')
				{
					blackEvaluate += 1;
				}
			}
		}

		break;
	}

	case 2:
	case 3:
	case 4:
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if ((i == 0 || i == 7) && (j == 0 || j == 7))
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 5;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 5;
					}
				}
				else if (i == 0 || i == 7 || j == 0 || j == 7)
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 2;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 2;
					}
				}
				else
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 1;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 1;
					}
				}
			}
		}
		break;
	}
	case 5:
	case 6:
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if ((i == 0 || i == 7) && (j == 0 || j == 7))
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 5;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 5;
					}
				}
				else if (i == 0 || i == 7 || j == 0 || j == 7)
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 2;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 2;
					}
				}
				else
				{
					if (board[i][j] == 'W')
					{
						whiteEvaluate += 1;
					}
					else if (board[i][j] == 'B')
					{
						blackEvaluate += 1;
					}
				}
			}
		}
		b = validMoves(board, 'B');
		w = validMoves(board, 'W');
		blackEvaluate = blackEvaluate * 2 + b.size();
		whiteEvaluate = whiteEvaluate * 2 + w.size();
		break;
	}
	case 7:
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (board[i][j] == 'W')
				{
					whiteEvaluate = whiteEvaluate + weight[getStability(board, { i,j })];

				}
				else if (board[i][j] == 'B')
				{
					blackEvaluate = blackEvaluate + weight[getStability(board, { i,j })];
				}
			}
		}
		b = validMoves(board, 'B');
		w = validMoves(board, 'W');
		sb = b.size();
		sw = w.size();
		blackEvaluate += sb;
		whiteEvaluate += sw;
		break;
	}

	}

	return blackEvaluate - whiteEvaluate;
}

int Minimax::getStability(char board[8][8], std::pair<int, int> p)
{
	char chessColor = board[p.first][p.second];
	char opponent;
	if (chessColor == 'B')
	{
		opponent = 'W';
	}
	else if (chessColor == 'W')
	{
		opponent = 'B';
	}

	int drow[4][2] = { { 0, 0 }, { -1, 1 }, { -1, 1 }, { 1, -1 } };
	int dcol[4][2] = { { -1, 1 }, { 0, 0 }, { -1, 1 }, { -1, 1 } };
	int row[2];
	int col[2];
	int degree = 0;
	for (int k = 0; k < 4; ++k)
	{
		row[0] = row[1] = p.first;
		col[0] = col[1] = p.second;
		for (int i = 0; i < 2; ++i)
		{
			while (isOnBoard(row[i] + drow[k][i], col[i] + dcol[k][i]) && board[row[i] + drow[k][i]][col[i] + dcol[k][i]] == chessColor)
			{
				row[i] += drow[k][i];
				col[i] += dcol[k][i];
			}
		}
		if (!isOnBoard(row[0] + drow[k][0], col[0] + dcol[k][0]) || !isOnBoard(row[1] + drow[k][1], col[1] + dcol[k][1]))
		{
			degree += 1;
		}
		else if (board[row[0] + drow[k][0]][col[0] + dcol[k][0]] == opponent && board[row[1] + drow[k][1]][col[1] + dcol[k][1]] == opponent)
		{
			degree += 1;
		}
	}

	return degree;
}


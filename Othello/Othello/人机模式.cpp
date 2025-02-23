#include<iostream>
using namespace std;
#include<iomanip>
char board[8][8];
int valid[8][8];
#include"Minimax.h"
#include"ai1.h"
#include"ai2.h"
#include"ai3.h"
#include"ai4.h"
#include"mini.h"
#include"ai0.h"

void initialBoard();	//初始化棋盘
void printBoard();		//绘制棋盘
bool haveValidMove(char player);	//判断是否有合法落子处
bool isValidMove(int row, int col, char player);
void getMove(int i, int j, char player);	//落子
void checkWin();	//判断棋局胜者



int main()
{
	initialBoard();
	char player = 'B';//黑棋先落子
	ai0 zero;
	ai3 three;

	while (true)
	{
		int row = 0;
		int col = 0;
		int opponent = (player == 'B') ? 'W' : 'B';

		//如果有合法落子处，则提示落子
		if (haveValidMove(player))
		{
			printBoard();
			if (player == 'W') cout << "白";
			if (player == 'B') cout << "黑";
			cout << "方：请输入下棋坐标 ";
		}
		else if (!haveValidMove(player) && haveValidMove(opponent))
		{
			printBoard();
			if (player == 1) cout << "白";
			if (player == 0) cout << "黑";
			cout << "方：本轮无合法落子处，pass ";
			player = (player == 'B') ? 'W' : 'B';
			system("cls");
			continue;
		}
		else if (!haveValidMove(player) && !haveValidMove(opponent))	//	如果双方都没有合法落点
		{
			checkWin();
			break;
		}

		if (player == 'B')
		{
			
			/*
			//处理输入异常
			while (true)
			{
				cin >> row >> col;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "请输入数字！" << endl;
				}
				else
				{
					break;
				}
			}
			*/

			
			std::pair<int, int> p = zero.ai(board, player);
			row = p.first;
			col = p.second;
			

		}
		else if (player == 'W')
		{
			std::pair<int, int> p = three.ai(board, player);
			row = p.first;
			col = p.second;
		}
		
		//如果下在合法处，则轮到对方落子
		if (isValidMove(row, col, player))
		{
			player = (player == 'B') ? 'W' : 'B';
			system("cls");
		}
		else if (!isValidMove(row, col, player))//如果不合法则重新下
		{
			system("cls");
			cout << "落子不合法，请重新落子。" << endl;
		}

		//判断是否有空位下
		bool empty = false;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (board[i][j] == ' ')
				{
					empty = true;
					break;
				}
			}
			if (empty)
			{
				break;
			}
		}

		if (!empty)
		{
			checkWin();
			break;
		}
	}


	system("pause");
	return 0;

}


//初始化棋盘
void initialBoard()
{
	//所有区域置空
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = ' ';
		}
	}

	//棋盘中央四个位置提前分布棋子
	board[3][3] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';
	board[4][4] = 'W';
}


//绘制棋盘
void printBoard()
{
	//绘制列号
	for (int i = 0; i < 8; ++i)
	{
		if (i == 0) cout << setw(2) << " ";
		cout << setw(2) << i;
		if (i == 7) cout << endl;
	}

	for (int i = 0; i < 8; ++i)
	{
		cout << setw(2) << i << "|";
		for (int j = 0; j < 8; ++j)
		{
	
			if (board[i][j] == ' ' && valid[i][j] == 0)
			{
				cout << " ";
			}
			else if (board[i][j] == ' ' && valid[i][j] == 1)
			{
				cout << "*";
			}
			else if (board[i][j] == 'B')
			{
				cout << "B";
			}
			else if (board[i][j] == 'W')
			{
				cout << "W";
			}
			else
			{
				cout << "?";
			}

			cout << "|";
		}
		cout << endl;
	}
}


//判断是否有合法落子处，并返回一个合法落子的坐标，储存在数组里
bool haveValidMove(char player)
{
	//每次判断一方是否有合法落子处时，都要将valid置为0
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			valid[i][j] = 0;
		}
	}

	bool checkReserve = false;
	char opponent;
	if (player == 'B')
	{
		opponent = 'W';
	}
	else if (player == 'W')
	{
		opponent = 'B';
	}

	for (int i = 0; i < 8; ++i)	//行 
	{
		for (int j = 0; j < 8; ++j)	//列
		{
			if (board[i][j] == ' ')
			{
				//x负方向扫描是否有夹住棋子
				if (j > 0 && j <= 7)
				{
					//向左扫描，直到左边不是对方棋子
					int k = j - 1;
					while (board[i][k] == opponent)
					{
						k--;
						if (k < 0)
						{
							break;
						}
					}

					//如果左边第一个就不是，那么不用判断
					//搜索到边了，也不用判断
					if (k != j - 1 && k >= 0)
					{
						if (board[i][k] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}
				}


				//x正方向扫描是否有夹住棋子
				if (j >= 0 && j < 7)
				{
					//向右扫描，直到右边不是对方棋子
					int k = j + 1;
					while (board[i][k] == opponent)
					{
						k++;
						if (k > 7)
						{
							break;
						}
					}

					//如果右边第一个就不是，那么不用判断
					//搜索到边了，也不用判断
					if (k != j + 1 && k <= 7)
					{
						if (board[i][k] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}

				//y正方向扫描是否有夹住棋子
				if (i > 0 && i <= 7)
				{
					//向上扫描，直到上边不是对方棋子
					int k = i - 1;
					while (board[k][j] == opponent)
					{
						k--;
						if (k < 0)
						{
							break;
						}
					}

					//如果上边第一个就不是，那么不用判断
					//搜索到边了，也不用判断
					if (k != i - 1 && k >= 0)
					{
						if (board[k][j] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}
				}

				//y负方向扫描是否有夹住棋子
				if (i >= 0 && i < 7)
				{
					//向下扫描，直到下边不是对方棋子
					int k = i + 1;
					while (board[k][j] == opponent)
					{
						k++;
						if (k > 7)
						{
							break;
						}
					}

					//如果下边第一个就不是，那么不用判断
					//搜索到边了，也不用判断
					if (k != i + 1 && k <= 7)
					{
						if (board[k][j] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}

				//右上方扫描是否有夹住棋子，两种情况不用检查右上方：
				//1、棋子在最上边  i==0
				//2、棋子在最右边  j==7
				if (i != 0 && j != 7)
				{
					//向右上方扫描，直到右上方不是对方棋子
					int row = i - 1;
					int col = j + 1;
					while (board[row][col] == opponent)
					{
						row--;
						col++;
						if (row < 0 || col>7)
						{
							break;
						}
					}

					//如果右上方第一个就不是，那么不用判断  
					//搜索到边了（上边和右边），也不用判断
					if (row != i - 1 && col != j + 1 && row >= 0 && col <= 7)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//左下方扫描是否有夹住棋子，两种情况不用检查左下方：
				//1、棋子在最下边  i==7
				//2、棋子在最左边  j==0
				if (i != 7 && j != 0)
				{
					//向左下方扫描，直到左下方不是对方棋子
					int row = i + 1;
					int col = j - 1;
					while (board[row][col] == opponent)
					{
						row++;
						col--;
						if (row > 7 || col < 0)
						{
							break;
						}
					}

					//如果左下方第一个就不是，那么不用判断  
					//搜索到边了（下边和左边），也不用判断
					if (row != i + 1 && col != j - 1 && row <= 7 && col >= 0)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//左上方扫描是否有夹住棋子，两种情况不用检查左上方：
				//1、棋子在最上边  i==0
				//2、棋子在最左边  j==0
				if (i != 0 && j != 0)
				{
					//向左上方扫描，直到左上方不是对方棋子
					int row = i - 1;
					int col = j - 1;
					while (board[row][col] == opponent)
					{
						row--;
						col--;
						if (row < 0 || col < 0)
						{
							break;
						}
					}

					//如果左上方第一个就不是，那么不用判断  
					//搜索到边了（上边和左边），也不用判断
					if (row != i - 1 && col != j - 1 && row >= 0 && col >= 0)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//右下方扫描是否有夹住棋子，两种情况不用检查右下方：
				//1、棋子在最下边  i==0
				//2、棋子在最右边  j==0
				if (i != 7 && j != 7)
				{
					//向右下方扫描，直到右下方不是对方棋子
					int row = i + 1;
					int col = j + 1;
					while (board[row][col] == opponent)
					{
						row++;
						col++;
						if (row > 7 || col > 7)
						{
							break;
						}
					}

					//如果右下方第一个就不是，那么不用判断  
					//搜索到边了（下边和右边），也不用判断
					if (row != i + 1 && col != j + 1 && row <= 7 && col <= 7)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


			}
		}
	}

	return checkReserve;
}



//落子且翻转
void getMove(int i, int j, char player)
{
	char opponent;
	if (player == 'B')
	{
		opponent = 'W';
	}
	else if (player == 'W')
	{
		opponent = 'B';
	}

	int Reverse[8][8] = { 0 };	//	记录需要翻转的位置

	//x负方向扫描是否有夹住棋子，有则翻转
	if (j > 0 && j <= 7)
	{
		//向左扫描，直到左边不是对方棋子
		int k = j - 1;
		while (board[i][k] == opponent)
		{
			k--;
			if (k < 0)
			{
				break;
			}
		}

		//如果左边第一个就不是，那么不用判断
		//搜索到边了，也不用判断
		if (k != j - 1 && k >= 0)
		{
			if (board[i][k] == player)
			{
				for (int y = k + 1; y < j; ++y)
				{
					Reverse[i][y] = 1;
				}
			}
		}
	}


	//x正方向扫描是否有夹住棋子，有则翻转
	if (j >= 0 && j < 7)
	{
		//向右扫描，直到右边不是对方棋子
		int k = j + 1;
		while (board[i][k] == opponent)
		{
			k++;
			if (k > 7)
			{
				break;
			}
		}

		//如果右边第一个就不是，那么不用判断
		//搜索到边了，也不用判断
		if (k != j + 1 && k <= 7)
		{
			if (board[i][k] == player)
			{
				for (int y = k - 1; y > j; --y)
				{
					Reverse[i][y] = 1;
				}
			}
		}

	}

	//y正方向扫描是否有夹住棋子，有则翻转
	if (i > 0 && i <= 7)
	{
		//向上扫描，直到上边不是对方棋子
		int k = i - 1;
		while (board[k][j] == opponent)
		{
			k--;
			if (k < 0)
			{
				break;
			}
		}

		//如果上边第一个就不是，那么不用判断
		//搜索到边了，也不用判断
		if (k != i - 1 && k >= 0)
		{
			if (board[k][j] == player)
			{
				for (int x = k + 1; x < i; ++x)
				{
					Reverse[x][j] = 1;
				}
			}
		}
	}

	//y负方向扫描是否有夹住棋子，有则翻转
	if (i >= 0 && i < 7)
	{
		//向下扫描，直到下边不是对方棋子
		int k = i + 1;
		while (board[k][j] == opponent)
		{
			k++;
			if (k > 7)
			{
				break;
			}
		}

		//如果下边第一个就不是，那么不用判断
		//搜索到边了，也不用判断
		if (k != i + 1 && k <= 7)
		{
			if (board[k][j] == player)
			{
				for (int x = k - 1; x > i; --x)
				{
					Reverse[x][j] = 1;
				}
			}
		}

	}

	//右上方扫描是否有夹住棋子，有则翻转，两种情况不用检查右上方：
	//1、棋子在最上边  i==0
	//2、棋子在最右边  j==7
	if (i != 0 && j != 7)
	{
		//向右上方扫描，直到右上方不是对方棋子
		int row = i - 1;
		int col = j + 1;
		while (board[row][col] == opponent)
		{
			row--;
			col++;
			if (row < 0 || col>7)
			{
				break;
			}
		}

		//如果右上方第一个就不是，那么不用判断  
		//搜索到边了（上边和右边），也不用判断
		if (row != i - 1 && col != j + 1 && row >= 0 && col <= 7)
		{
			if (board[row][col] == player)
			{
				int x = row + 1;
				int y = col - 1;
				for (; x < i && y > j; ++x, --y)
				{
					Reverse[x][y] = 1;
				}
			}
		}

	}


	//左下方扫描是否有夹住棋子，有则翻转，两种情况不用检查左下方：
	//1、棋子在最下边  i==7
	//2、棋子在最左边  j==0
	if (i != 7 && j != 0)
	{
		//向左下方扫描，直到左下方不是对方棋子
		int row = i + 1;
		int col = j - 1;
		while (board[row][col] == opponent)
		{
			row++;
			col--;
			if (row > 7 || col < 0)
			{
				break;
			}
		}

		//如果左下方第一个就不是，那么不用判断  
		//搜索到边了（下边和左边），也不用判断
		if (row != i + 1 && col != j - 1 && row <= 7 && col >= 0)
		{
			if (board[row][col] == player)
			{
				int x = row - 1;
				int y = col + 1;
				for (; x > i && y < j; --x, ++y)
				{
					Reverse[x][y] = 1;
				}
			}
		}

	}


	//左上方扫描是否有夹住棋子，有则翻转，两种情况不用检查左上方：
	//1、棋子在最上边  i==0
	//2、棋子在最左边  j==0
	if (i != 0 && j != 0)
	{
		//向左上方扫描，直到左上方不是对方棋子
		int row = i - 1;
		int col = j - 1;
		while (board[row][col] == opponent)
		{
			row--;
			col--;
			if (row < 0 || col < 0)
			{
				break;
			}
		}

		//如果左上方第一个就不是，那么不用判断  
		//搜索到边了（上边和左边），也不用判断
		if (row != i - 1 && col != j - 1 && row >= 0 && col >= 0)
		{
			if (board[row][col] == player)
			{
				int x = row + 1;
				int y = col + 1;
				for (; x < i && y < j; x++, y++)
				{
					Reverse[x][y] = 1;
				}
			}
		}

	}


	//右下方扫描是否有夹住棋子，有则翻转，两种情况不用检查右下方：
	//1、棋子在最下边  i==0
	//2、棋子在最右边  j==0
	if (i != 7 && j != 7)
	{
		//向右下方扫描，直到右下方不是对方棋子
		int row = i + 1;
		int col = j + 1;
		while (board[row][col] == opponent)
		{
			row++;
			col++;
			if (row > 7 || col > 7)
			{
				break;
			}
		}

		//如果右下方第一个就不是，那么不用判断  
		//搜索到边了（下边和右边），也不用判断
		if (row != i + 1 && col != j + 1 && row <= 7 && col <= 7)
		{
			if (board[row][col] == player)
			{
				int x = row - 1;
				int y = col - 1;
				for (; x > i && y > j; --x, --y)
				{
					Reverse[x][y] = 1;
				}
			}
		}

	}

	board[i][j] = player;
	for (int m = 0; m < 8; ++m)
	{
		for (int n = 0; n < 8; ++n)
		{
			if (Reverse[m][n] == 1)
			{
				board[m][n] = player;
			}
		}
	}

}


//判断落子是否合法
bool isValidMove(int row, int col, char player)
{
	if (board[row][col] != ' ')	//	如果落子处非空
	{
		return false;
	}
	else if (board[row][col] == ' ' && valid[row][col] == 1)	//如果下在空的地方且会造成翻转
	{
		getMove(row, col, player);
		return true;
	}
	else if (board[row][col] == ' ' && valid[row][col] == 0)	//	如果下在空的地方且没有造成翻转，需要重新下
	{
		return false;
	}
}


//判断棋局是否结束
void checkWin()
{
	int blackCount = 0;
	int whiteCount = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j] == 'B')
			{
				blackCount++;
			}
			else if (board[i][j] == 'W')
			{
				whiteCount++;
			}
		}
	}

	printBoard();
	cout << "黑棋：" << blackCount << "\t白棋：" << whiteCount << endl;
	if (blackCount > whiteCount)
	{
		cout << "黑棋获胜！" << endl;
	}
	else if (blackCount < whiteCount)
	{
		cout << "白棋获胜！" << endl;
	}
	else if (blackCount = whiteCount)
	{
		cout << "黑白平局！" << endl;
	}


}

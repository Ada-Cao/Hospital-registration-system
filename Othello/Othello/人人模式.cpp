#include<iostream>
using namespace std;
#include<iomanip>
#define BOARD_SIZE 8
char board[8][8];	//棋盘，记录当前棋局
int valid[8][8];	//记录玩家当前落子的合法位置，合法则置为1，不合法置为0

//最好是要处理一下异常，即输入其他字符时候
//0---黑方
//1---白方

void initialBoard();	//初始化棋盘
void printBoard();		//绘制棋盘
bool haveValidMove(int player);	//判断是否有合法落子处
bool isValidMove(int row, int col, int player);	//判断落子是否合法并翻转
void getMove(int i, int j, int player);	//落子
void checkWin();	//判断棋局胜者

int main()
{
	initialBoard();
	int player = 0;//黑棋先落子

	while (true)
	{
		int row = 0;
		int col = 0;
		int opponent = (player + 1) % 2;

		//如果有合法落子处，则提示落子
		if (haveValidMove(player))
		{
			printBoard();
			if (player == 1) cout << "白";
			if (player == 0) cout << "黑";
			cout << "方：请输入下棋坐标 ";
		}
		else if (!haveValidMove(player) && haveValidMove(opponent))
		{
			printBoard();
			if (player == 1) cout << "白";
			if (player == 0) cout << "黑";
			cout << "方：本轮无合法落子处，pass ";
			player = (player + 1) % 2;
			system("cls");
			continue;
		}
		else if (!haveValidMove(player) && !haveValidMove(opponent))	//	如果双方都没有合法落点
		{
			checkWin();
			break;
		}

		/*
		//test ：输出所有合法位置
		cout << endl;
		cout << " ";
		int xxx = 0;
		for (int i = 0; i < 8; ++i)
		{
			cout << setw(2) << i;
		}
		cout << endl;

		for (int i = 0; i < 8; ++i)
		{
			cout << i << " ";
			for (int j = 0; j < 8; ++j)
			{
				cout << valid[i][j] << " ";
				if (++xxx % 8 == 0) cout << endl;
			}
		}
		*/

		//处理输入异常
		while(true)
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

		//如果下在合法处，则轮到对方落子
		if (isValidMove(row, col, player))
		{
			player = (player + 1) % 2;
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
				if (board[i][j] == -1)
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
			board[i][j] = -1;
		}
	}

	//棋盘中央四个位置提前分布棋子
	board[3][3] = 1;
	board[3][4] = 0;
	board[4][3] = 0;
	board[4][4] = 1;
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
			//如果数组元素是-1，代表没有落子
			//如果数组元素是0，代表已落黑子
			//如果数组元素是1，代表已落白子
			if (board[i][j] == -1 && valid[i][j] == 0)
			{
				cout << " ";
			}
			else if (board[i][j] == -1 && valid[i][j] == 1)
			{
				cout << "*";
			}
			else if (board[i][j] == 0)
			{
				cout << "B";
			}
			else if (board[i][j] == 1)
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
bool haveValidMove(int player)
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
	int opponent = (player + 1) % 2;

	for (int i = 0; i < 8; ++i)	//行 
	{
		for (int j = 0; j < 8; ++j)	//列
		{
			if (board[i][j] == -1)
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
void getMove(int i, int j, int player)
{
	int opponent = (player + 1) % 2;
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
bool isValidMove(int row, int col, int player)
{
	if (board[row][col] != -1)	//	如果落子处非空
	{
		return false;
	}
	else if (board[row][col] == -1 && valid[row][col] == 1)	//如果下在空的地方且会造成翻转
	{
		getMove(row, col, player);
		return true;
	}
	else if (board[row][col] == -1 && valid[row][col] == 0)	//	如果下在空的地方且没有造成翻转，需要重新下
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
			if (board[i][j] == 0)
			{
				blackCount++;
			}
			else if (board[i][j] == 1)
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




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

void initialBoard();	//��ʼ������
void printBoard();		//��������
bool haveValidMove(char player);	//�ж��Ƿ��кϷ����Ӵ�
bool isValidMove(int row, int col, char player);
void getMove(int i, int j, char player);	//����
void checkWin();	//�ж����ʤ��



int main()
{
	initialBoard();
	char player = 'B';//����������
	ai0 zero;
	ai3 three;

	while (true)
	{
		int row = 0;
		int col = 0;
		int opponent = (player == 'B') ? 'W' : 'B';

		//����кϷ����Ӵ�������ʾ����
		if (haveValidMove(player))
		{
			printBoard();
			if (player == 'W') cout << "��";
			if (player == 'B') cout << "��";
			cout << "������������������ ";
		}
		else if (!haveValidMove(player) && haveValidMove(opponent))
		{
			printBoard();
			if (player == 1) cout << "��";
			if (player == 0) cout << "��";
			cout << "���������޺Ϸ����Ӵ���pass ";
			player = (player == 'B') ? 'W' : 'B';
			system("cls");
			continue;
		}
		else if (!haveValidMove(player) && !haveValidMove(opponent))	//	���˫����û�кϷ����
		{
			checkWin();
			break;
		}

		if (player == 'B')
		{
			
			/*
			//���������쳣
			while (true)
			{
				cin >> row >> col;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "���������֣�" << endl;
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
		
		//������ںϷ��������ֵ��Է�����
		if (isValidMove(row, col, player))
		{
			player = (player == 'B') ? 'W' : 'B';
			system("cls");
		}
		else if (!isValidMove(row, col, player))//������Ϸ���������
		{
			system("cls");
			cout << "���Ӳ��Ϸ������������ӡ�" << endl;
		}

		//�ж��Ƿ��п�λ��
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


//��ʼ������
void initialBoard()
{
	//���������ÿ�
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = ' ';
		}
	}

	//���������ĸ�λ����ǰ�ֲ�����
	board[3][3] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';
	board[4][4] = 'W';
}


//��������
void printBoard()
{
	//�����к�
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


//�ж��Ƿ��кϷ����Ӵ���������һ���Ϸ����ӵ����꣬������������
bool haveValidMove(char player)
{
	//ÿ���ж�һ���Ƿ��кϷ����Ӵ�ʱ����Ҫ��valid��Ϊ0
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

	for (int i = 0; i < 8; ++i)	//�� 
	{
		for (int j = 0; j < 8; ++j)	//��
		{
			if (board[i][j] == ' ')
			{
				//x������ɨ���Ƿ��м�ס����
				if (j > 0 && j <= 7)
				{
					//����ɨ�裬ֱ����߲��ǶԷ�����
					int k = j - 1;
					while (board[i][k] == opponent)
					{
						k--;
						if (k < 0)
						{
							break;
						}
					}

					//�����ߵ�һ���Ͳ��ǣ���ô�����ж�
					//���������ˣ�Ҳ�����ж�
					if (k != j - 1 && k >= 0)
					{
						if (board[i][k] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}
				}


				//x������ɨ���Ƿ��м�ס����
				if (j >= 0 && j < 7)
				{
					//����ɨ�裬ֱ���ұ߲��ǶԷ�����
					int k = j + 1;
					while (board[i][k] == opponent)
					{
						k++;
						if (k > 7)
						{
							break;
						}
					}

					//����ұߵ�һ���Ͳ��ǣ���ô�����ж�
					//���������ˣ�Ҳ�����ж�
					if (k != j + 1 && k <= 7)
					{
						if (board[i][k] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}

				//y������ɨ���Ƿ��м�ס����
				if (i > 0 && i <= 7)
				{
					//����ɨ�裬ֱ���ϱ߲��ǶԷ�����
					int k = i - 1;
					while (board[k][j] == opponent)
					{
						k--;
						if (k < 0)
						{
							break;
						}
					}

					//����ϱߵ�һ���Ͳ��ǣ���ô�����ж�
					//���������ˣ�Ҳ�����ж�
					if (k != i - 1 && k >= 0)
					{
						if (board[k][j] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}
				}

				//y������ɨ���Ƿ��м�ס����
				if (i >= 0 && i < 7)
				{
					//����ɨ�裬ֱ���±߲��ǶԷ�����
					int k = i + 1;
					while (board[k][j] == opponent)
					{
						k++;
						if (k > 7)
						{
							break;
						}
					}

					//����±ߵ�һ���Ͳ��ǣ���ô�����ж�
					//���������ˣ�Ҳ�����ж�
					if (k != i + 1 && k <= 7)
					{
						if (board[k][j] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}

				//���Ϸ�ɨ���Ƿ��м�ס���ӣ�����������ü�����Ϸ���
				//1�����������ϱ�  i==0
				//2�����������ұ�  j==7
				if (i != 0 && j != 7)
				{
					//�����Ϸ�ɨ�裬ֱ�����Ϸ����ǶԷ�����
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

					//������Ϸ���һ���Ͳ��ǣ���ô�����ж�  
					//���������ˣ��ϱߺ��ұߣ���Ҳ�����ж�
					if (row != i - 1 && col != j + 1 && row >= 0 && col <= 7)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//���·�ɨ���Ƿ��м�ס���ӣ�����������ü�����·���
				//1�����������±�  i==7
				//2�������������  j==0
				if (i != 7 && j != 0)
				{
					//�����·�ɨ�裬ֱ�����·����ǶԷ�����
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

					//������·���һ���Ͳ��ǣ���ô�����ж�  
					//���������ˣ��±ߺ���ߣ���Ҳ�����ж�
					if (row != i + 1 && col != j - 1 && row <= 7 && col >= 0)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//���Ϸ�ɨ���Ƿ��м�ס���ӣ�����������ü�����Ϸ���
				//1�����������ϱ�  i==0
				//2�������������  j==0
				if (i != 0 && j != 0)
				{
					//�����Ϸ�ɨ�裬ֱ�����Ϸ����ǶԷ�����
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

					//������Ϸ���һ���Ͳ��ǣ���ô�����ж�  
					//���������ˣ��ϱߺ���ߣ���Ҳ�����ж�
					if (row != i - 1 && col != j - 1 && row >= 0 && col >= 0)
					{
						if (board[row][col] == player)
						{
							checkReserve = true;
							valid[i][j] = 1;
						}
					}

				}


				//���·�ɨ���Ƿ��м�ס���ӣ�����������ü�����·���
				//1�����������±�  i==0
				//2�����������ұ�  j==0
				if (i != 7 && j != 7)
				{
					//�����·�ɨ�裬ֱ�����·����ǶԷ�����
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

					//������·���һ���Ͳ��ǣ���ô�����ж�  
					//���������ˣ��±ߺ��ұߣ���Ҳ�����ж�
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



//�����ҷ�ת
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

	int Reverse[8][8] = { 0 };	//	��¼��Ҫ��ת��λ��

	//x������ɨ���Ƿ��м�ס���ӣ�����ת
	if (j > 0 && j <= 7)
	{
		//����ɨ�裬ֱ����߲��ǶԷ�����
		int k = j - 1;
		while (board[i][k] == opponent)
		{
			k--;
			if (k < 0)
			{
				break;
			}
		}

		//�����ߵ�һ���Ͳ��ǣ���ô�����ж�
		//���������ˣ�Ҳ�����ж�
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


	//x������ɨ���Ƿ��м�ס���ӣ�����ת
	if (j >= 0 && j < 7)
	{
		//����ɨ�裬ֱ���ұ߲��ǶԷ�����
		int k = j + 1;
		while (board[i][k] == opponent)
		{
			k++;
			if (k > 7)
			{
				break;
			}
		}

		//����ұߵ�һ���Ͳ��ǣ���ô�����ж�
		//���������ˣ�Ҳ�����ж�
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

	//y������ɨ���Ƿ��м�ס���ӣ�����ת
	if (i > 0 && i <= 7)
	{
		//����ɨ�裬ֱ���ϱ߲��ǶԷ�����
		int k = i - 1;
		while (board[k][j] == opponent)
		{
			k--;
			if (k < 0)
			{
				break;
			}
		}

		//����ϱߵ�һ���Ͳ��ǣ���ô�����ж�
		//���������ˣ�Ҳ�����ж�
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

	//y������ɨ���Ƿ��м�ס���ӣ�����ת
	if (i >= 0 && i < 7)
	{
		//����ɨ�裬ֱ���±߲��ǶԷ�����
		int k = i + 1;
		while (board[k][j] == opponent)
		{
			k++;
			if (k > 7)
			{
				break;
			}
		}

		//����±ߵ�һ���Ͳ��ǣ���ô�����ж�
		//���������ˣ�Ҳ�����ж�
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

	//���Ϸ�ɨ���Ƿ��м�ס���ӣ�����ת������������ü�����Ϸ���
	//1�����������ϱ�  i==0
	//2�����������ұ�  j==7
	if (i != 0 && j != 7)
	{
		//�����Ϸ�ɨ�裬ֱ�����Ϸ����ǶԷ�����
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

		//������Ϸ���һ���Ͳ��ǣ���ô�����ж�  
		//���������ˣ��ϱߺ��ұߣ���Ҳ�����ж�
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


	//���·�ɨ���Ƿ��м�ס���ӣ�����ת������������ü�����·���
	//1�����������±�  i==7
	//2�������������  j==0
	if (i != 7 && j != 0)
	{
		//�����·�ɨ�裬ֱ�����·����ǶԷ�����
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

		//������·���һ���Ͳ��ǣ���ô�����ж�  
		//���������ˣ��±ߺ���ߣ���Ҳ�����ж�
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


	//���Ϸ�ɨ���Ƿ��м�ס���ӣ�����ת������������ü�����Ϸ���
	//1�����������ϱ�  i==0
	//2�������������  j==0
	if (i != 0 && j != 0)
	{
		//�����Ϸ�ɨ�裬ֱ�����Ϸ����ǶԷ�����
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

		//������Ϸ���һ���Ͳ��ǣ���ô�����ж�  
		//���������ˣ��ϱߺ���ߣ���Ҳ�����ж�
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


	//���·�ɨ���Ƿ��м�ס���ӣ�����ת������������ü�����·���
	//1�����������±�  i==0
	//2�����������ұ�  j==0
	if (i != 7 && j != 7)
	{
		//�����·�ɨ�裬ֱ�����·����ǶԷ�����
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

		//������·���һ���Ͳ��ǣ���ô�����ж�  
		//���������ˣ��±ߺ��ұߣ���Ҳ�����ж�
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


//�ж������Ƿ�Ϸ�
bool isValidMove(int row, int col, char player)
{
	if (board[row][col] != ' ')	//	������Ӵ��ǿ�
	{
		return false;
	}
	else if (board[row][col] == ' ' && valid[row][col] == 1)	//������ڿյĵط��һ���ɷ�ת
	{
		getMove(row, col, player);
		return true;
	}
	else if (board[row][col] == ' ' && valid[row][col] == 0)	//	������ڿյĵط���û����ɷ�ת����Ҫ������
	{
		return false;
	}
}


//�ж�����Ƿ����
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
	cout << "���壺" << blackCount << "\t���壺" << whiteCount << endl;
	if (blackCount > whiteCount)
	{
		cout << "�����ʤ��" << endl;
	}
	else if (blackCount < whiteCount)
	{
		cout << "�����ʤ��" << endl;
	}
	else if (blackCount = whiteCount)
	{
		cout << "�ڰ�ƽ�֣�" << endl;
	}


}

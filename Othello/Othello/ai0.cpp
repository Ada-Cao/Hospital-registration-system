#include "ai0.h"
#include<ctime>
#include<cstdlib>
#include<vector>

//ai����
std::pair<int, int> ai0::ai(char board[8][8], char player)
{
	//��¼ÿ���Ϸ�����λ�����ܷ�ת�����Ӹ���
	int valid[8][8] = { 0 };
	char opponent;
	if (player == 'B')
	{
		opponent = 'W';
	}
	else if (player == 'W')
	{
		opponent = 'B';
	}
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j] == ' ')
			{
				for (int k = 0; k < 8; ++k)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					int count = 0;
					while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == opponent)
					{
						x += dx[k];
						y += dy[k];
						count++;
					}
					if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == player)
					{
						valid[i][j] += count;
					}
				}
			}
		}
	}

	//����λ�ø����ȼ�
	int priority[8][8] = {
	   {1, 9, 2, 4, 4, 2, 9, 1},
	   {9, 10, 8, 7, 7, 8, 10, 9},
	   {2, 8, 3, 5, 5, 3, 8, 2},
	   {4, 7, 5, 6, 6, 5, 7, 4},
	   {4, 7, 5, 6, 6, 5, 7, 4},
	   {2, 8, 3, 5, 5, 3, 8, 2},
	   {9, 10, 8, 7, 7, 8, 10, 9},
	   {1, 9, 2, 4, 4, 2, 9, 1}
	};

	//�����±߽Ǵ�
	if (valid[0][0] > 0)
	{
		return{ 0,0 };
	}
	else if (valid[0][7] > 0)
	{
		return { 0,7 };
	}
	else if (valid[7][0] > 0)
	{
		return { 7,0 };
	}
	else if (valid[7][7] > 0)
	{
		return { 7,7 };
	}

	//�����⵽û�кϷ�λ��
	bool empty = true;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (valid[i][j] > 0)
			{
				empty = false;
				break;
			}
		}
	}
	if (empty)
	{
		return{ -1,-1 };
	}

	//�����·�ת����λ�ã�������ͬ��Ƚ����ȼ�
	int row = -1;
	int col = -1;
	int value = 0;
	srand(((unsigned int)time(0)));
	for (int i = 0; i < 8; ++i)	//��¼����ܷ�ת��������
	{
		for (int j = 0; j < 8; ++j)
		{
			if (valid[i][j] == 0) continue;
			if (valid[i][j] > value)
			{
				value = valid[i][j];
			}
		}
	}
	std::vector<std::pair<int, int>> mosts;	//���������෭ת��λ��
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (valid[i][j] == value)
			{
				mosts.push_back({ i,j });
			}
		}
	}

	//ȷ�����ȼ���ߵ�
	std::vector<std::pair<int, int>> bests;
	int bestone = 100;
	for (int i = 0; i < mosts.size(); ++i)
	{
		if (priority[mosts[i].first][mosts[i].second] < bestone)
		{
			bestone = priority[mosts[i].first][mosts[i].second];
		}
	}
	for (int i = 0; i < mosts.size(); ++i)
	{
		if (priority[mosts[i].first][mosts[i].second] == bestone)
		{
			bests.push_back(mosts[i]);	//bests������������һ��Ԫ��
		}
	}


	//����1�����öԷ��¶Խ�
	//����һ��������
	char nboard[8][8];
	int index = 0;
	//����������ӵ�
	std::vector<std::pair<int, int>> nbests(bests);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			nboard[i][j] = board[i][j];
		}
	}

	for (int k = 0; k < bests.size(); ++k)
	{
		//����һ��
		nboard[bests[k].first][bests[k].second] = player;
		int nvalid[8][8] = { 0 };
		int dx1[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
		int dy1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{	
				if (nboard[i][j] == ' ')
				{
					for (int k = 0; k < 8; ++k)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						int count = 0;
						while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == player)
						{
							x += dx[k];
							y += dy[k];
							count++;
						}
						if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == opponent)
						{
							nvalid[i][j] += count;
						}
					}
				}
			}
		}

		//������öԷ��¶Խǣ���ôɾ�����Ԫ��
		if (nvalid[0][0] > 0 || nvalid[0][7] > 0 || nvalid[7][0] > 0 || nvalid[7][7] > 0)
		{
			nbests.erase(nbests.begin()+k-index);
			index++;
		}

		//����
		nboard[bests[k].first][bests[k].second] = ' ';
	}
	
	if (nbests.size() == 0)
	{
		int size = bests.size();
		return bests[rand() % size];
	}
	

	//����2���öԷ����ܷ�ת���������ٵ���һ��
	std::vector<std::pair<int, int>> finalChoices;
	for (int k = 0; k < nbests.size(); ++k)
	{
		int curPosIndex = k;
		int opponentMaxFlip = 0;
		//����һ��
		nboard[nbests[k].first][nbests[k].second] = player;
		int nvalid[8][8] = { 0 };
		int dx1[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
		int dy1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (nboard[i][j] == ' ')
				{
					for (int k = 0; k < 8; ++k)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						int count = 0;
						while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == player)
						{
							x += dx[k];
							y += dy[k];
							count++;
						}
						if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == opponent)
						{
							nvalid[i][j] += count;
						}
					}
				}
			}
		}

		//����
		nboard[nbests[k].first][nbests[k].second] = ' ';

		for (int m = 0; m < 8; ++m)
		{
			for (int n = 0; n < 8; ++n)
			{
				if (nvalid[m][n] > opponentMaxFlip)
				{
					opponentMaxFlip = nvalid[m][n];
				}
			}
		}
		if (opponentMaxFlip < value)
		{
			finalChoices.push_back(nbests[curPosIndex]);
		}
	}

	if (finalChoices.size() > 0)
	{
		int finalSize = finalChoices.size();
		std::pair<int, int> finalRst = finalChoices[rand() % finalSize];
		return finalRst;
	}
	else
	{
		int size = nbests.size();
		return nbests[rand()%size];
	}
}

#include "ai1.h"
#include<ctime>
#include<cstdlib>
#include<vector>

/*
//ai����
std::pair<int, int> ai1::ai(char board[8][8], char player)
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
	   {1, 5, 3, 3, 3, 3, 5, 1},
	   {5, 5, 4, 4, 4, 4, 5, 5},
	   {3, 4, 2, 2, 2, 2, 4, 3},
	   {3, 4, 2, 0, 0, 2, 4, 3},
	   {3, 4, 2, 0, 0, 2, 4, 3},
	   {3, 4, 2, 2, 2, 2, 4, 3},
	   {5, 5, 4, 4, 4, 4, 5, 5},
	   {1, 5, 3, 3, 3, 3, 5, 1}
	};

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
			bests.push_back(mosts[i]);
		}
	}

	int size = bests.size();
	std::pair<int, int>rst = bests[rand() % size];

	return rst;
}
*/
std::pair<int, int> ai1::ai(char board[8][8], char player)
{
    // ��¼ÿ���Ϸ�����λ�����ܷ�ת�����Ӹ���
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

    // ����λ�ø����ȼ���������Ը���ʵ�ʶ��ľ���Ƚ�һ������������ȼ�����ʹAI�����ܣ�
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

    // �������ж���ͨ�Եĸ������飬���ڼ�¼ÿ����λ��Χͬɫ���ӵ���ͨ��������ʼ��Ϊ0��
    int connectivity[8][8] = { 0 };

    // ����ÿ����λ����ͨ�ԣ�������Χͬɫ����������������ͨ�ԣ��ɸ���ʵ�ʸ�ϸ������
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == ' ')
            {
                int sameColorCount = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == player)
                    {
                        sameColorCount++;
                    }
                }
                connectivity[i][j] = sameColorCount;
            }
        }
    }

    // �����±߽Ǵ�������λ��ͨ����ֵ�ϸߣ����жϽ����Ƿ�����ӣ�������ͨ�Ժ����ȼ������ߣ�
    if (valid[0][0] > 0)
    {
        return { 0, 0 };
    }
    else if (valid[0][7] > 0)
    {
        return { 0, 7 };
    }
    else if (valid[7][0] > 0)
    {
        return { 7, 0 };
    }
    else if (valid[7][7] > 0)
    {
        return { 7, 7 };
    }

    // ��¼����ۺϵ÷֣��ۺϿ��ǿɷ�ת����������ͨ�ԡ�λ�����ȼ������أ��Լ���Ӧ��λ��
    int maxScore = -1;
    std::vector<std::pair<int, int>> maxScorePositions;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (valid[i][j] > 0)
            {
                // �����ۺϵ÷֣�����򵥼�Ȩ���ɸ���ʵ�ʵ���Ȩ�أ�ʹ������ռ�ȸ�����
                // ���磺�ɷ�ת������Ȩ��3����ͨ��Ȩ��2��λ�����ȼ�Ȩ��1
                int score = valid[i][j] *2  + connectivity[i][j] * 2 + (10 - priority[i][j])*2;
                if (score > maxScore)
                {
                    maxScore = score;
                    maxScorePositions.clear();
                    maxScorePositions.push_back({ i, j });
                }
                else if (score == maxScore)
                {
                    maxScorePositions.push_back({ i, j });
                }
            }
        }
    }

    // ���ֻ��һ���ۺϵ÷���ߵ�λ�ã�ֱ�ӷ��ظ�λ��
    if (maxScorePositions.size() == 1)
    {
        return maxScorePositions[0];
    }

    // ���ڶ���ۺϵ÷���ߵ�λ�ã����ѡ��һ�����أ��ɸ���ʵ����Ӹ�ϸ�µ����ֹ���
    int size = maxScorePositions.size();
    std::pair<int, int> rst = maxScorePositions[rand() % size];
    return rst;
}
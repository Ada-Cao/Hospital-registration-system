#include "ai1.h"
#include<ctime>
#include<cstdlib>
#include<vector>

/*
//ai落子
std::pair<int, int> ai1::ai(char board[8][8], char player)
{
	//记录每个合法落子位置所能翻转的棋子个数
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

	
	//各个位置附优先级
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

	//优先下边角处
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
	for (int i = 0; i < 8; ++i)	//记录最多能翻转几个棋子
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
	std::vector<std::pair<int, int>> mosts;	//存放所有最多翻转的位置
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
    // 记录每个合法落子位置所能翻转的棋子个数
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

    // 各个位置附优先级（这里可以根据实际对弈经验等进一步调整这个优先级矩阵，使AI更智能）
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

    // 新增：判断连通性的辅助数组，用于记录每个空位周围同色棋子的连通数量（初始化为0）
    int connectivity[8][8] = { 0 };

    // 计算每个空位的连通性，简单以周围同色棋子数量来衡量连通性（可根据实际更细化规则）
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

    // 优先下边角处（角落位置通常价值较高，先判断角落是否可落子，角落连通性和优先级都更高）
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

    // 记录最大综合得分（综合考虑可翻转棋子数、连通性、位置优先级等因素）以及对应的位置
    int maxScore = -1;
    std::vector<std::pair<int, int>> maxScorePositions;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (valid[i][j] > 0)
            {
                // 计算综合得分，这里简单加权（可根据实际调整权重，使各因素占比更合理）
                // 例如：可翻转棋子数权重3，连通性权重2，位置优先级权重1
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

    // 如果只有一个综合得分最高的位置，直接返回该位置
    if (maxScorePositions.size() == 1)
    {
        return maxScorePositions[0];
    }

    // 存在多个综合得分最高的位置，随机选择一个返回（可根据实际添加更细致的区分规则）
    int size = maxScorePositions.size();
    std::pair<int, int> rst = maxScorePositions[rand() % size];
    return rst;
}
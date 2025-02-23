#include "ai3.h"
#include<ctime>
#include<cstdlib>
#include<functional>
#include<cstring>

// 判断位置是否在棋盘内
bool ai3::inBoard(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// 计算稳定的棋子数量
int ai3::countStablePieces(char board[8][8], char player) {
	int stableCount = 0;
	// 角上的棋子是稳定的
	if (board[0][0] == player) stableCount++;
	if (board[0][7] == player) stableCount++;
	if (board[7][0] == player) stableCount++;
	if (board[7][7] == player) stableCount++;

	// 边缘棋子的稳定性判断（这里简单判断相邻位置为同色则稳定）
	for (int i = 1; i < 7; ++i) {
		if (board[0][i] == player && board[0][i - 1] == player && board[0][i + 1] == player) stableCount++;
		if (board[i][0] == player && board[i - 1][0] == player && board[i + 1][0] == player) stableCount++;
		if (board[7][i] == player && board[7][i - 1] == player && board[7][i + 1] == player) stableCount++;
		if (board[i][7] == player && board[i - 1][7] == player && board[i + 1][7] == player) stableCount++;
	}
	return stableCount;
}

// 计算合法移动数量
int ai3::countValidMoves(char board[8][8], char player) {
	int count = 0;
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == ' ') {
				for (int k = 0; k < 8; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					bool valid = false;
					while (inBoard(x, y) && board[x][y] == (player == 'B' ? 'W' : 'B')) {
						x += dx[k];
						y += dy[k];
						if (inBoard(x, y) && board[x][y] == player) {
							valid = true;
							break;
						}
					}
					if (valid) {
						count++;
						break;
					}
				}
			}
		}
	}
	return count;
}

// 计算棋子分布的评估值（简单示例：计算同色棋子的连通区域数量）
int ai3::countConnectedRegions(char board[8][8], char player) {
	int regions = 0;
	bool visited[8][8] = { false };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

	// 使用std::function定义dfs，指定其为接受两个int参数，无返回值的可调用对象类型
	std::function<void(int, int)> dfs = [&](int x, int y) {
		visited[x][y] = true;
		for (int k = 0; k < 8; ++k) {
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (inBoard(newX, newY) && board[newX][newY] == player && !visited[newX][newY]) {
				dfs(newX, newY);
			}
		}
		};

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == player && !visited[i][j]) {
				dfs(i, j);
				regions++;
			}
		}
	}
	return regions;
}

// ai落子
std::pair<int, int> ai3::ai(char board[8][8], char player) {
	// 记录每个合法落子位置所能翻转的棋子个数
	int valid[8][8] = { 0 };
	char opponent = (player == 'B' ? 'W' : 'B');
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == ' ') {
				for (int k = 0; k < 8; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					int count = 0;
					while (inBoard(x, y) && board[x][y] == opponent) {
						x += dx[k];
						y += dy[k];
						count++;
					}
					if (inBoard(x, y) && board[x][y] == player) {
						valid[i][j] += count;
					}
				}
			}
		}
	}

	/*
	// 各个位置附优先级
	int priority[8][8] = {
		{1, 5, 3, 3, 3, 3, 5, 1},
		{5, 5, 4, 4, 4, 4, 5, 5},
		{3, 4, 2, 2, 2, 2, 4, 3},
		{3, 4, 2, 0, 0, 2, 4, 3},
		{3, 4, 2, 0, 0, 2, 4, 3},
		{3, 4, 2, 2, 2, 2, 4, 3},
		{5, 5, 4, 4, 4, 4, 5, 5},
		{1, 5, 3, 3, 3, 3, 5, 1}
	};*/

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

	// 优先下边角处
	if (valid[0][0] > 0) {
		return { 0,0 };
	}
	else if (valid[0][7] > 0) {
		return { 0,7 };
	}
	else if (valid[7][0] > 0) {
		return { 7,0 };
	}
	else if (valid[7][7] > 0) {
		return { 7,7 };
	}

	int row = -1;
	int col = -1;
	int bestScore = -9999;
	// 初始化随机数生成器
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (valid[i][j] == 0) continue;
			// 模拟落子
			char newBoard[8][8];
			for (int m = 0; m < 8; ++m) {
				for (int n = 0; n < 8; ++n) {
					newBoard[m][n] = board[m][n];
				}
			}
			newBoard[i][j] = player;
			// 评估函数
			int stablePlayer = countStablePieces(newBoard, player);
			int stableOpponent = countStablePieces(newBoard, opponent);
			int validMovesPlayer = countValidMoves(newBoard, player);
			int validMovesOpponent = countValidMoves(newBoard, opponent);
			int regionsPlayer = countConnectedRegions(newBoard, player);
			int regionsOpponent = countConnectedRegions(newBoard, opponent);
			int score = (valid[i][j] * 2) + (stablePlayer - stableOpponent) + (validMovesPlayer - validMovesOpponent) + (regionsOpponent - regionsPlayer);
			if (score > bestScore) {
				bestScore = score;
				row = i;
				col = j;
			}
		}
	}
	if (row == -1 && col == -1) {
		// 如果没有找到合法的落子位置，返回一个无效位置（这里返回{-1, -1}）
		return { -1, -1 };
	}
	return { row, col };
}
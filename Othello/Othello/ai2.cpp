#include "ai2.h"
#include<ctime>
#include<cstdlib>
#include<vector>

// �ж�λ���Ƿ���������
bool ai2::inBoard(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// ����Ϸ��ƶ�����
int ai2::countValidMoves(char board[8][8], char player) {
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

// ����ǵĿ�������
int ai2::countCornerControl(char board[8][8], char player) {
	int count = 0;
	if (board[0][0] == player) count++;
	if (board[0][7] == player) count++;
	if (board[7][0] == player) count++;
	if (board[7][7] == player) count++;
	return count;
}



// ai����
std::pair<int, int> ai2::ai(char board[8][8], char player) {
	// ��¼ÿ���Ϸ�����λ�����ܷ�ת�����Ӹ���
	int valid[8][8] = { 0 };
	char opponent;
	if (player == 'B') {
		opponent = 'W';
	}
	else if (player == 'W') {
		opponent = 'B';
	}
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == ' ') {
				for (int k = 0; k < 8; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					int count = 0;
					while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == opponent) {
						x += dx[k];
						y += dy[k];
						count++;
					}
					if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == player) {
						valid[i][j] += count;
					}
				}
			}
		}
	}

	// ����λ�ø����ȼ�
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

	// �����±߽Ǵ�
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
	int value = 0;
	// ��ʼ�������������
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < 8; ++i) {  // ��¼����ܷ�ת��������
		for (int j = 0; j < 8; ++j) {
			if (valid[i][j] == 0) continue;
			if (valid[i][j] > value) {
				value = valid[i][j];
			}
		}
	}
	std::vector<std::pair<int, int>> mosts;  // ���������෭ת��λ��
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (valid[i][j] == value) {
				mosts.push_back({ i,j });
			}
		}
	}

	std::vector<std::pair<int, int>> bests;
	int bestone = 10;
	for (int i = 0; i < mosts.size(); ++i) {
		if (priority[mosts[i].first][mosts[i].second] < bestone) {
			bestone = priority[mosts[i].first][mosts[i].second];
		}
	}
	for (int i = 0; i < mosts.size(); ++i) {
		if (priority[mosts[i].first][mosts[i].second] == bestone) {
			bests.push_back(mosts[i]);
		}
	}

	int size = bests.size();
	if (size == 0) {
		// ���û���ҵ��Ϸ�������λ�ã�����һ����Чλ�ã����ﷵ��{-1, -1}��
		return { -1, -1 };
	}
	std::pair<int, int> rst = bests[std::rand() % size];

	return rst;
}


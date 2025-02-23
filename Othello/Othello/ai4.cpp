#include "ai4.h"
#include<ctime>
#include<cstdlib>
#include<functional>
#include<cstring>


// �ж�λ���Ƿ���������
bool ai4::inBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// �ж��ڸ�������״̬�£���ָ��λ�������Ƿ�Ϸ������ڵ�ǰ��ң�
bool ai4::isValidMove(char board[8][8], char player, int row, int col) {
    char opponent = (player == 'B' ? 'W' : 'B');
    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    for (int k = 0; k < 8; ++k) {
        int x = row + dx[k];
        int y = col + dy[k];
        bool foundOpponent = false;
        while (inBoard(x, y) && board[x][y] == opponent) {
            x += dx[k];
            y += dy[k];
            if (inBoard(x, y) && board[x][y] == player) {
                foundOpponent = true;
                break;
            }
        }
        if (foundOpponent) return true;
    }
    return false;
}

// ��ȡ��ǰ����ڸ�������״̬�µ����кϷ�����λ��
std::vector<std::pair<int, int>> ai4::getValidMoves(char board[8][8], char player) {
    std::vector<std::pair<int, int>> validMoves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == ' ' && isValidMove(board, player, i, j)) {
                validMoves.push_back({ i, j });
            }
        }
    }
    return validMoves;
}

// ��������״̬������ģ������ʱ��Ӱ��ԭ����
void ai4::copyBoard(char srcBoard[8][8], char destBoard[8][8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            destBoard[i][j] = srcBoard[i][j];
        }
    }
}

// ��������ִ�����Ӳ�������ʵ�֣�����ݺڰ���������ƶԷ�ת���ӵȴ���
void ai4::makeMove(char board[8][8], char player, int row, int col) {
    board[row][col] = player;
    // ���������Ӵ�����������Ӧ�����ӷ�ת�߼���������������򲢷�ת�������ӵ�
}


// �����ȶ�����������
int ai4::countStablePieces(char board[8][8], char player) {
    int stableCount = 0;
    // ���ϵ��������ȶ���
    if (board[0][0] == player) stableCount++;
    if (board[0][7] == player) stableCount++;
    if (board[7][0] == player) stableCount++;
    if (board[7][7] == player) stableCount++;

    // ��Ե���ӵ��ȶ����жϣ�������ж�����λ��Ϊͬɫ���ȶ���
    for (int i = 1; i < 7; ++i) {
        if (board[0][i] == player && board[0][i - 1] == player && board[0][i + 1] == player) stableCount++;
        if (board[i][0] == player && board[i - 1][0] == player && board[i + 1][0] == player) stableCount++;
        if (board[7][i] == player && board[7][i - 1] == player && board[7][i + 1] == player) stableCount++;
        if (board[i][7] == player && board[i - 1][7] == player && board[i + 1][7] == player) stableCount++;
    }
    return stableCount;
}

// ����Ϸ��ƶ�����
int ai4::countValidMoves(char board[8][8], char player) {
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

// �������ӷֲ�������ֵ����ʾ��������ͬɫ���ӵ���ͨ����������
int ai4::countConnectedRegions(char board[8][8], char player) {
    int regions = 0;
    bool visited[8][8] = { false };
    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    // ʹ��std::function����dfs��ָ����Ϊ��������int�������޷���ֵ�Ŀɵ��ö�������
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

// ����һ���ϴ�������������޺����ޣ�����Alpha - Beta��֦
const int MAX_SCORE = 9999;
const int MIN_SCORE = -9999;

// �ۺ��������̾��棨ʾ�����ɸ���ʵ�ʽ�һ���Ż�����Ȩ�غ����أ�
int ai4::evaluateBoard(char board[8][8], char player) {
    int score = 0;
    // ���Կ��Ǽ���֮ǰ�ᵽ���ȶ������������ƶ��ԡ���ͨ��������ص�����
    score += countStablePieces(board, player) - countStablePieces(board, (player == 'B' ? 'W' : 'B'));
    score += countValidMoves(board, player) - countValidMoves(board, (player == 'B' ? 'W' : 'B'));
    score += countConnectedRegions(board, player) - countConnectedRegions(board, (player == 'B' ? 'W' : 'B'));
    return score;
}

// Alpha - Beta��֦��������
int ai4::alphaBetaSearch(char board[8][8], char player, int depth, int alpha, int beta) {
    if (depth == 0) {
        // ��������������ƣ����ص�ǰ���������ֵ
        return evaluateBoard(board, player);
    }
    char opponent = (player == 'B' ? 'W' : 'B');
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        if (getValidMoves(board, opponent).empty()) {
            // ˫�����޺Ϸ����ӣ���Ϸ���������ص�ǰ��������ֵ
            return evaluateBoard(board, player);
        }
        // �Լ��޺Ϸ����ӣ����ּ������ӣ��л���Ҽ�������
        return alphaBetaSearch(board, opponent, depth - 1, -beta, -alpha);
    }
    for (const auto& move : validMoves) {
        char newBoard[8][8];
        copyBoard(board, newBoard);
        makeMove(newBoard, player, move.first, move.second);
        int score = -alphaBetaSearch(newBoard, opponent, depth - 1, -beta, -alpha);
        if (score >= beta) {
            return beta;
        }
        alpha = std::max(alpha, score);
    }
    return alpha;
}

// ai����
std::pair<int, int> ai4::ai(char board[8][8], char player) {
    int bestScore = MIN_SCORE;
    std::pair<int, int> bestMove = { -1, -1 };
    int depth = 3;  // ����������ȣ��ɸ���ʵ��������������Խ�������Խ�󵫾��߿��ܸ���
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    for (const auto& move : validMoves) {
        char newBoard[8][8];
        copyBoard(board, newBoard);
        makeMove(newBoard, player, move.first, move.second);
        int score = alphaBetaSearch(newBoard, (player == 'B' ? 'W' : 'B'), depth - 1, MIN_SCORE, MAX_SCORE);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}



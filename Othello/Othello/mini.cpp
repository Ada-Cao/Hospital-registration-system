#include "mini.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <functional>


// �ж�λ���Ƿ���������
bool mini::inBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// �жϸ���λ�������Ƿ�Ϸ������ںڰ������������̲�����
bool mini::isValidMove(char board[8][8], char player, int row, int col) {
    char opponent = (player == 'B' ? 'W' : 'B');
    if (board[row][col] != ' ') return false;
    for (int d = 0; d < 8; ++d) {
        int x = row + directions[d][0];
        int y = col + directions[d][1];
        bool foundOpponent = false;
        while (inBoard(x, y) && board[x][y] == opponent) {
            x += directions[d][0];
            y += directions[d][1];
            if (inBoard(x, y) && board[x][y] == player) {
                foundOpponent = true;
                break;
            }
        }
        if (foundOpponent) return true;
    }
    return false;
}

// ��ȡ��ǰ��ҵ����кϷ��ƶ�λ�ã�������̲�����
std::vector<std::pair<int, int>> mini::getValidMoves(char board[8][8], char player) {
    std::vector<std::pair<int, int>> validMoves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (isValidMove(board, player, i, j)) {
                validMoves.push_back(std::make_pair(i, j));
            }
        }
    }
    return validMoves;
}

// ��������ִ�����Ӳ�������ת��Ӧ���ӣ����ݺڰ������������̲�����
void mini::makeMove(char board[8][8], char player, int row, int col) {
    board[row][col] = player;
    char opponent = (player == 'B' ? 'W' : 'B');
    for (int d = 0; d < 8; ++d) {
        int x = row + directions[d][0];
        int y = col + directions[d][1];
        bool foundOpponent = false;
        std::vector<std::pair<int, int>> toFlip;
        while (inBoard(x, y) && board[x][y] == opponent) {
            x += directions[d][0];
            y += directions[d][1];
            if (inBoard(x, y) && board[x][y] == player) {
                foundOpponent = true;
                break;
            }
            toFlip.push_back(std::make_pair(x, y));
        }
        if (foundOpponent) {
            // �����жϣ�ȷ��Ҫ��ת�������м�û�б���ϣ������Ͻ���ִ�з�ת����
            bool canFlip = true;
            for (const auto& pos : toFlip) {
                int checkX = pos.first + directions[d][0];
                int checkY = pos.second + directions[d][1];
                if (!inBoard(checkX, checkY) || board[checkX][checkY] != opponent) {
                    canFlip = false;
                    break;
                }
            }
            if (canFlip) {
                for (const auto& pos : toFlip) {
                    board[pos.first][pos.second] = player;
                }
            }
        }
    }
}

// ��������״̬������ģ�����Ӳ�Ӱ��ԭ���̣�������̲�����
void mini::copyBoard(char src[8][8], char dest[8][8]) {
    std::memcpy(dest, src, sizeof(src));
}

// ����������ͨ�ԣ�������ͨ����������������̲�����
int mini::countConnectedRegions(char board[8][8], char player) {
    bool visited[8][8] = { false };
    int regions = 0;
    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    // ʹ��std::function����dfs������ݹ���ñ�������
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

// �����Ե������������ر�Ե���Լ�����������ȥ��������������������̲�����
int mini::countEdgeControl(char board[8][8], char player) {
    int myEdgePieces = 0;
    int opponentEdgePieces = 0;
    for (int i = 0; i < 8; ++i) {
        if (board[0][i] == player) myEdgePieces++;
        else if (board[0][i] == (player == 'B' ? 'W' : 'B')) opponentEdgePieces++;

        if (board[7][i] == player) myEdgePieces++;
        else if (board[7][i] == (player == 'B' ? 'W' : 'B')) opponentEdgePieces++;

        if (board[i][0] == player) myEdgePieces++;
        else if (board[i][0] == (player == 'B' ? 'W' : 'B')) opponentEdgePieces++;

        if (board[i][7] == player) myEdgePieces++;
        else if (board[i][7] == (player == 'B' ? 'W' : 'B')) opponentEdgePieces++;
    }
    return myEdgePieces - opponentEdgePieces;
}

// ����ʽ�����������ۺ��������̾�������ӣ�������̲�����
int mini::evaluateBoard(char board[8][8], char player) {
    int score = 0;
    // ����������ֵ
    int myPieces = 0, opponentPieces = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == player) myPieces++;
            else if (board[i][j] == (player == 'B' ? 'W' : 'B')) opponentPieces++;
        }
    }
    score += myPieces - opponentPieces;

    // ����ռ�ݽǵ�������Ǻ���Ҫ��
    if (board[0][0] == player) score += 10;
    if (board[0][7] == player) score += 10;
    if (board[7][0] == player) score += 10;
    if (board[7][7] == player) score += 10;
    // �ͷ�����ռ�ݽǵ����
    if (board[0][0] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[0][7] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[7][0] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[7][7] == (player == 'B' ? 'W' : 'B')) score -= 10;

    // ��Ե�����������
    score += countEdgeControl(board, player) * 2;

    // ������ͨ����������ͨ�����ٿ��ܸ��ÿ��ƾ��棩
    score += (countConnectedRegions(board, (player == 'B' ? 'W' : 'B')) - countConnectedRegions(board, player)) * 3;

    return score;
}

// Minimax�㷨���ĺ�������������������Ӳ��ԣ�������̲�����
int mini::minimax(char board[8][8], char player, int depth, bool maximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board, player);
    }
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        char opponent = (player == 'B' ? 'W' : 'B');
        // �������Ƿ��кϷ�����λ��
        std::vector<std::pair<int, int>> opponentValidMoves = getValidMoves(board, opponent);
        if (opponentValidMoves.empty()) {
            // ˫�����޺Ϸ����ӣ����ݾ�������������棬����򵥷��ص�ǰ��������ֵ�����Ż�
            return evaluateBoard(board, player);
        }
        return minimax(board, opponent, depth - 1, !maximizingPlayer);
    }
    if (maximizingPlayer) {
        int maxEval = -10000;
        for (const auto& move : validMoves) {
            char newBoard[8][8];
            copyBoard(board, newBoard);
            makeMove(newBoard, player, move.first, move.second);
            int eval = minimax(newBoard, (player == 'B' ? 'W' : 'B'), depth - 1, false);
            maxEval = std::max(maxEval, eval);
        }
        return maxEval;
    }
    else {
        int minEval = 10000;
        for (const auto& move : validMoves) {
            char newBoard[8][8];
            copyBoard(board, newBoard);
            makeMove(newBoard, player, move.first, move.second);
            int eval = minimax(newBoard, (player == 'B' ? 'W' : 'B'), depth - 1, true);
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
}

// AI���Ӻ���������Minimax�㷨���о��ߣ������ⲿ���̺���Ҳ���
std::pair<int, int> mini::ai(char board[8][8], char player) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        return std::make_pair(-1, -1);
    }
    int bestScore = -10000;
    std::pair<int, int> bestMove;
    int depth = 4;  // �ɵ���������ȣ����Խ�����Խ��ʱ�����߿��ܸ���
    for (const auto& move : validMoves) {
        char newBoard[8][8];
        copyBoard(board, newBoard);
        makeMove(newBoard, player, move.first, move.second);
        int score = minimax(newBoard, (player == 'B' ? 'W' : 'B'), depth - 1, false);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    // ������֤ѡ����������λ���Ƿ�Ϸ�
    if (!isValidMove(board, player, bestMove.first, bestMove.second)) {
        // ������Ϸ����ɸ���ʵ���������ѡ������򵥷����޺Ϸ�λ�ñ�ǣ����Ż�
        return std::make_pair(-1, -1);
    }
    return bestMove;
}

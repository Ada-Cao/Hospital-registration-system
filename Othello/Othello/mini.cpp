#include "mini.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <functional>


// 判断位置是否在棋盘内
bool mini::inBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// 判断给定位置落子是否合法（基于黑白棋规则，添加棋盘参数）
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

// 获取当前玩家的所有合法移动位置（添加棋盘参数）
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

// 在棋盘上执行落子操作并翻转相应棋子（根据黑白棋规则，添加棋盘参数）
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
            // 增加判断，确保要翻转的棋子中间没有被阻断，更加严谨地执行翻转操作
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

// 复制棋盘状态（用于模拟落子不影响原棋盘，添加棋盘参数）
void mini::copyBoard(char src[8][8], char dest[8][8]) {
    std::memcpy(dest, src, sizeof(src));
}

// 计算棋子连通性（返回连通区域数量，添加棋盘参数）
int mini::countConnectedRegions(char board[8][8], char player) {
    bool visited[8][8] = { false };
    int regions = 0;
    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    // 使用std::function定义dfs，解决递归调用报错问题
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

// 计算边缘控制情况（返回边缘上自己棋子数量减去对手棋子数量，添加棋盘参数）
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

// 启发式评估函数（综合评估棋盘局面的优劣，添加棋盘参数）
int mini::evaluateBoard(char board[8][8], char player) {
    int score = 0;
    // 棋子数量差值
    int myPieces = 0, opponentPieces = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == player) myPieces++;
            else if (board[i][j] == (player == 'B' ? 'W' : 'B')) opponentPieces++;
        }
    }
    score += myPieces - opponentPieces;

    // 奖励占据角的情况（角很重要）
    if (board[0][0] == player) score += 10;
    if (board[0][7] == player) score += 10;
    if (board[7][0] == player) score += 10;
    if (board[7][7] == player) score += 10;
    // 惩罚对手占据角的情况
    if (board[0][0] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[0][7] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[7][0] == (player == 'B' ? 'W' : 'B')) score -= 10;
    if (board[7][7] == (player == 'B' ? 'W' : 'B')) score -= 10;

    // 边缘控制情况评估
    score += countEdgeControl(board, player) * 2;

    // 棋子连通性评估（连通区域少可能更好控制局面）
    score += (countConnectedRegions(board, (player == 'B' ? 'W' : 'B')) - countConnectedRegions(board, player)) * 3;

    return score;
}

// Minimax算法核心函数，用于搜索最佳落子策略（添加棋盘参数）
int mini::minimax(char board[8][8], char player, int depth, bool maximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board, player);
    }
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        char opponent = (player == 'B' ? 'W' : 'B');
        // 检查对手是否有合法落子位置
        std::vector<std::pair<int, int>> opponentValidMoves = getValidMoves(board, opponent);
        if (opponentValidMoves.empty()) {
            // 双方都无合法落子，根据具体规则评估局面，这里简单返回当前局面评估值，可优化
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

// AI落子函数，整合Minimax算法进行决策，接收外部棋盘和玩家参数
std::pair<int, int> mini::ai(char board[8][8], char player) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        return std::make_pair(-1, -1);
    }
    int bestScore = -10000;
    std::pair<int, int> bestMove;
    int depth = 4;  // 可调整搜索深度，深度越大计算越耗时但决策可能更好
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
    // 最终验证选择的最佳落子位置是否合法
    if (!isValidMove(board, player, bestMove.first, bestMove.second)) {
        // 如果不合法，可根据实际情况重新选择，这里简单返回无合法位置标记，可优化
        return std::make_pair(-1, -1);
    }
    return bestMove;
}

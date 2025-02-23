#include "ai4.h"
#include<ctime>
#include<cstdlib>
#include<functional>
#include<cstring>


// 判断位置是否在棋盘内
bool ai4::inBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// 判断在给定棋盘状态下，在指定位置落子是否合法（对于当前玩家）
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

// 获取当前玩家在给定棋盘状态下的所有合法落子位置
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

// 复制棋盘状态，用于模拟落子时不影响原棋盘
void ai4::copyBoard(char srcBoard[8][8], char destBoard[8][8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            destBoard[i][j] = srcBoard[i][j];
        }
    }
}

// 在棋盘上执行落子操作（简单实现，需根据黑白棋规则完善对翻转棋子等处理）
void ai4::makeMove(char board[8][8], char player, int row, int col) {
    board[row][col] = player;
    // 这里可以添加代码来处理相应的棋子翻转逻辑，比如检查各个方向并翻转对手棋子等
}


// 计算稳定的棋子数量
int ai4::countStablePieces(char board[8][8], char player) {
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

// 计算棋子分布的评估值（简单示例：计算同色棋子的连通区域数量）
int ai4::countConnectedRegions(char board[8][8], char player) {
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

// 定义一个较大的评估分数上限和下限，用于Alpha - Beta剪枝
const int MAX_SCORE = 9999;
const int MIN_SCORE = -9999;

// 综合评估棋盘局面（示例，可根据实际进一步优化各项权重和因素）
int ai4::evaluateBoard(char board[8][8], char player) {
    int score = 0;
    // 可以考虑加入之前提到的稳定棋子数量、移动性、连通区域等因素的评估
    score += countStablePieces(board, player) - countStablePieces(board, (player == 'B' ? 'W' : 'B'));
    score += countValidMoves(board, player) - countValidMoves(board, (player == 'B' ? 'W' : 'B'));
    score += countConnectedRegions(board, player) - countConnectedRegions(board, (player == 'B' ? 'W' : 'B'));
    return score;
}

// Alpha - Beta剪枝搜索函数
int ai4::alphaBetaSearch(char board[8][8], char player, int depth, int alpha, int beta) {
    if (depth == 0) {
        // 到达搜索深度限制，返回当前局面的评估值
        return evaluateBoard(board, player);
    }
    char opponent = (player == 'B' ? 'W' : 'B');
    std::vector<std::pair<int, int>> validMoves = getValidMoves(board, player);
    if (validMoves.empty()) {
        if (getValidMoves(board, opponent).empty()) {
            // 双方都无合法落子，游戏结束，返回当前局面评估值
            return evaluateBoard(board, player);
        }
        // 自己无合法落子，对手继续落子，切换玩家继续搜索
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

// ai落子
std::pair<int, int> ai4::ai(char board[8][8], char player) {
    int bestScore = MIN_SCORE;
    std::pair<int, int> bestMove = { -1, -1 };
    int depth = 3;  // 设置搜索深度，可根据实际情况调整，深度越大计算量越大但决策可能更优
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



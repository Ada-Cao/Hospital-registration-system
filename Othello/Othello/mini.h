#pragma once
#include <vector>
#include <utility>

class mini
{
public:
    // 判断位置是否在棋盘内（保持不变，因为功能独立通用）
    static bool inBoard(int x, int y);

    // 判断给定位置落子是否合法（基于黑白棋规则，添加棋盘参数）
    bool isValidMove(char board[8][8], char player, int row, int col);

    // 获取当前玩家的所有合法移动位置（添加棋盘参数）
    std::vector<std::pair<int, int>> getValidMoves(char board[8][8], char player);

    // 在棋盘上执行落子操作并翻转相应棋子（根据黑白棋规则，添加棋盘参数）
    void makeMove(char board[8][8], char player, int row, int col);

    // 复制棋盘状态（用于模拟落子不影响原棋盘，添加棋盘参数）
    void copyBoard(char src[8][8], char dest[8][8]);

    // 启发式评估函数（综合评估棋盘局面的优劣，添加棋盘参数）
    int evaluateBoard(char board[8][8], char player);

    // Minimax算法核心函数，用于搜索最佳落子策略（添加棋盘参数）
    int minimax(char board[8][8], char player, int depth, bool maximizingPlayer);

    // AI落子函数，整合Minimax算法进行决策，接收外部棋盘和玩家参数
    std::pair<int, int> ai(char board[8][8], char player);

private:
    // 方向数组，用于遍历周围格子（保持不变）
    int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1}, {1, 0}, {1, 1}
    };

    // 计算棋子连通性（返回连通区域数量，添加棋盘参数）
    int countConnectedRegions(char board[8][8], char player);

    // 计算边缘控制情况（返回边缘上自己棋子数量减去对手棋子数量，添加棋盘参数）
    int countEdgeControl(char board[8][8], char player);

};


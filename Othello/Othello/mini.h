#pragma once
#include <vector>
#include <utility>

class mini
{
public:
    // �ж�λ���Ƿ��������ڣ����ֲ��䣬��Ϊ���ܶ���ͨ�ã�
    static bool inBoard(int x, int y);

    // �жϸ���λ�������Ƿ�Ϸ������ںڰ������������̲�����
    bool isValidMove(char board[8][8], char player, int row, int col);

    // ��ȡ��ǰ��ҵ����кϷ��ƶ�λ�ã�������̲�����
    std::vector<std::pair<int, int>> getValidMoves(char board[8][8], char player);

    // ��������ִ�����Ӳ�������ת��Ӧ���ӣ����ݺڰ������������̲�����
    void makeMove(char board[8][8], char player, int row, int col);

    // ��������״̬������ģ�����Ӳ�Ӱ��ԭ���̣�������̲�����
    void copyBoard(char src[8][8], char dest[8][8]);

    // ����ʽ�����������ۺ��������̾�������ӣ�������̲�����
    int evaluateBoard(char board[8][8], char player);

    // Minimax�㷨���ĺ�������������������Ӳ��ԣ�������̲�����
    int minimax(char board[8][8], char player, int depth, bool maximizingPlayer);

    // AI���Ӻ���������Minimax�㷨���о��ߣ������ⲿ���̺���Ҳ���
    std::pair<int, int> ai(char board[8][8], char player);

private:
    // �������飬���ڱ�����Χ���ӣ����ֲ��䣩
    int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1}, {1, 0}, {1, 1}
    };

    // ����������ͨ�ԣ�������ͨ����������������̲�����
    int countConnectedRegions(char board[8][8], char player);

    // �����Ե������������ر�Ե���Լ�����������ȥ��������������������̲�����
    int countEdgeControl(char board[8][8], char player);

};


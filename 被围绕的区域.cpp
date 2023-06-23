/*
����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е�?'O' �� 'X' ��䡣
ʾ�� 1��
���룺board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
�����[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
���ͣ���Χ�Ƶ����䲻������ڱ߽��ϣ����仰˵���κα߽��ϵ�?'O'?�����ᱻ���Ϊ?'X'�� �κβ��ڱ߽��ϣ�����߽��ϵ�?'O'?������?'O'?���ն��ᱻ���Ϊ?'X'���������Ԫ����ˮƽ��ֱ�������ڣ���������ǡ��������ġ�
ʾ�� 2��
���룺board = [["X"]]
�����[["X"]]
��ʾ��
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] Ϊ 'X' �� 'O'
*/

class Solution {
    int a[4] = {1, -1, 0, 0}, b[4] = {0, 0, 1, -1};
    void BFS(vector<vector<char>>& v, int x, int y)
    {
        if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size() || v[x][y] != 'O')
            return;
        v[x][y] = '1';
        for (int i = 0; i < 4; i++) BFS(v, x + a[i], y + b[i]);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int y = 0; y < n; y++)
        {
            BFS(board, 0, y);
            BFS(board, m - 1, y);
        }
        for (int x = 1; x < m - 1; x++)
        {
            BFS(board, x, 0);
            BFS(board, x, n - 1);
        }

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (board[x][y] == 'O')
                    board[x][y] = 'X';
                else if (board[x][y] == '1')
                    board[x][y] = 'O';
            }
        }
    }
};


/*
����һ����СΪ m x n �������һ���������ʼ����Ϊ [startRow, startColumn] ������Խ����Ƶ����ĸ����������ڵĵ�Ԫ���ڣ����Դ�������߽絽������֮�⣩���� ��� �����ƶ� maxMove ����
����������� m��n��maxMove��startRow �Լ� startColumn ���ҳ������ؿ��Խ����Ƴ��߽��·����������Ϊ�𰸿��ܷǳ��󣬷��ض� 10^9 + 7 ȡ�� ��Ľ����
ʾ�� 1��
���룺m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
�����6
ʾ�� 2��
���룺m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
�����12
��ʾ��
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/
class Solution {
    int x  = 1e9 + 7, m, n;
    int dp[51][51][51];
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return DFS(startRow, startColumn, maxMove);
    }

    long DFS(int i, int j, int d)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;            // ����
        if (d == 0)
            return 0;            // û�в���
        if (dp[i][j][d] != -1)
            return dp[i][j][d];  // ֮ǰ����
        return dp[i][j][d] = (DFS(i + 1, j, d - 1) + DFS(i - 1, j, d - 1) + DFS(i, j + 1, d - 1) + DFS(i, j - 1, d - 1)) % x;
    }
};

// �������������DFS���������ж������֮ǰ���������ꡢ������ͬ��״̬
// �����ظ����㣺�ü��������¼ÿ��״̬���յ�·������������´��ظ��������״̬��ֱ��ȡ��·��������������������


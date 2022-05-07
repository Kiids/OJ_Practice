/*
��һ�� n x n �Ĺ������������ϣ�һ����ʿ�ӵ�Ԫ�� (row, column) ��ʼ�������Խ��� k ���ƶ����к����� �� 0 ��ʼ �ģ��������ϵ�Ԫ���� (0,0) �����µ�Ԫ���� (n - 1, n - 1) ��
������ʿ��8�ֿ��ܵ��߷�������ͼ��ʾ��ÿ���ƶ��ڻ�����������������Ԫ��Ȼ����������������һ����Ԫ��
ÿ����ʿҪ�ƶ�ʱ�������������8�ֿ��ܵ��ƶ���ѡ��һ��(��ʹ���ӻ��뿪����)��Ȼ���ƶ������
��ʿ�����ƶ���ֱ�������� k �����뿪�����̡�
���� ��ʿ������ֹͣ�ƶ��������������ϵĸ��� ��
ʾ�� 1��
����: n = 3, k = 2, row = 0, column = 0
���: 0.0625
����: ������(��(1,2)��(2,1))��������ʿ���������ϡ�
��ÿһ��λ���ϣ�Ҳ�������ƶ���������ʿ���������ϡ�
��ʿ���������ϵ��ܸ�����0.0625��
ʾ�� 2��
����: n = 1, k = 0, row = 0, column = 0
���: 1.00000
��ʾ:
1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n
*/

class Solution {
    int x[8] = {-2,-2,-1,-1,1,1,2,2};
    int y[8] = {1,-1,2,-2,2,-2,1,-1};
    unordered_map<int, unordered_map<int, double>> mem;
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0)
            return 1;
        if (mem[row * n + column].find(k) != mem[row * n + column].end())
            return mem[row * n + column][k];

        double ret = 0;
        for (int i = 0; i < 8; i++)
        {
            int r = row + x[i];
            int c = column + y[i];
            if (r >= n || c >= n || r < 0 || c < 0)
                continue;
            ret += knightProbability(n, k-1, r, c) / 8;
        }

        mem[row * n + column][k] = ret;
        return ret;
    }
};

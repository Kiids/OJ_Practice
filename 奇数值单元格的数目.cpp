/*
����һ�� n �� m �еľ����ʼ��ʱ��ÿ����Ԫ���е�ֵ���� 0��
����һ���������� indices��indices[i] = [ri, ci] �е� ri �� ci �ֱ��ʾָ�����к��У��� 0 ��ʼ��ţ���
����Ҫ��ÿ�� [ri, ci] ָ�����к����ϵ����е�Ԫ���ֵ�� 1��
������ִ�������� indices ָ�������������󣬷��ؾ����� ������ֵ��Ԫ�� ����Ŀ��
ʾ�� 1��
���룺n = 2, m = 3, indices = [[0,1],[1,1]]
�����6
���ͣ��ʼ�ľ����� [[0,0,0],[0,0,0]]��
��һ������������õ� [[1,2,1],[0,1,0]]��
���ľ����� [[1,3,1],[1,3,1]]�������� 6 ��������
ʾ�� 2��
���룺n = 2, m = 2, indices = [[1,1],[0,0]]
�����0
���ͣ����ľ����� [[2,2],[2,2]]������û��������
��ʾ��
1 <= n <= 50
1 <= m <= 50
1 <= indices.length <= 100
0 <= indices[i][0] < n
0 <= indices[i][1] < m
*/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (auto indice : indices)
        {
            rows[indice[0]]++;
            cols[indice[1]]++;
        }
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if((rows[i] + cols[j]) % 2)
                    ret += 1;
        return ret;
    }
};

/*
��һ����ά���� A ����ÿ��Ԫ�ص�ֵΪ 0 �� 1 ��
�ƶ���ָѡ����һ�л��У���ת�����л����е�ÿһ��ֵ�������� 0 ������Ϊ 1�������� 1 ������Ϊ 0��
����������������ƶ��󣬽��þ����ÿһ�ж����ն������������ͣ�����ĵ÷־�����Щ���ֵ��ܺ͡�
���ؾ����ܸߵķ�����
ʾ����
���룺[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
�����39
���ͣ�
ת��Ϊ [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
��ʾ��
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] �� 0 �� 1
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n0 = 0, n1 = 0, ret = 0;
        int n = grid.size(), m = grid[0].size();
        if (n == 0 && m == 0)
            return ret;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == 0 && grid[j][i] == 0)
                    for (int k = 0; k < m; k++)
                        grid[j][k] = -(grid[j][k] - 1);
                else
                    grid[j][i] ? n1++ : n0++;
            if (n0 > n1)  // �жϷ�ת���������� 
                for (int j = 0; j < n; j++)
                    grid[j][i] = -(grid[j][i] - 1);
            for (int j = 0; j < n; j++)
                if (grid[j][i])
                    ret += pow(2, m - i - 1);
            n0 = n1 = 0;
        }
        return ret;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int i = 0, j = 0, sum = 0, ret = 0;
        ret = grid.size() * (1 << (grid[0].size() - 1));  // ���ÿһ�еĵ�һ����Ԫ�ز�Ϊ�㣬��ת���У�ʹ����Ԫ����0����ʱ��0�е�����ȫΪ1����� 
        for (j = 1; j < grid[0].size(); j++)
        {
            for (sum = 0, i = 0; i < grid.size(); i++)
            {
                if (grid[i][0])
                    sum += grid[i][j];
                else
                    sum += 1 - grid[i][j];
            }
            // sum = max(sum, grid.size() - sum);
            sum = sum > (grid.size() - sum) ? sum : (grid.size() - sum);
            ret += sum * (1 << (grid[0].size() - 1 - j));
        }
        return ret;
    }
};

// ̰��
// ���ÿһ�еĵ�һ����Ԫ�ز�Ϊ�㣬��ת���У�ʹ����Ԫ����0����ʱ��0�е�����ȫΪ1��
// Ȼ����������У�ʹÿһ�е�1�ĸ��������ܵĶ�Щ��
// ʱ�临�Ӷ�:O(n*m)


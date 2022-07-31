/*
����������СΪ n x n �Ķ����ƾ��� mat �� target ���� �� 90 ��˳ʱ����ת ���� mat �е�Ԫ�� ���ɴ� ������ܹ�ʹ mat ��?target һ�£����� true �����򣬷��� false ��
ʾ�� 1��
���룺mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
�����true
���ͣ�˳ʱ����ת 90 ��һ�ο���ʹ mat �� target һ�¡�
ʾ�� 2��
���룺mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
�����false
���ͣ��޷�ͨ����ת�����е�Ԫ��ʹ equal �� target һ�¡�
ʾ�� 3��
���룺mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
�����true
���ͣ�˳ʱ����ת 90 �����ο���ʹ mat �� target һ�¡�
��ʾ��
n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] �� target[i][j] ���� 0 ���� 1
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 4; i++)
        {
            vector<vector<int>> v = mat;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                    mat[j][k] = v[n - k - 1][j];
            }
            if (mat == target)
                return true;
        }
        return false;
    }
};

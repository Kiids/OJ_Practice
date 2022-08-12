/*
���һ�������ξ����������� ȫ�� ���������֮Ϊһ�� X ���� ��
����Խ����ϵ�����Ԫ�ض� ���� 0
��������������Ԫ�ض��� 0
����һ����СΪ n x n �Ķ�ά�������� grid ����ʾһ�������ξ������ grid ��һ�� X ���� ������ true �����򣬷��� false ��
ʾ�� 1��
���룺grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
�����true
���ͣ���������ͼ��ʾ��
X ����Ӧ�����㣺��ɫԪ�أ��Խ����ϣ������� 0 ����ɫԪ�ض��� 0 ��
��ˣ�grid ��һ�� X ����
ʾ�� 2��
���룺grid = [[5,7,0],[0,3,1],[0,5,0]]
�����false
���ͣ���������ͼ��ʾ��
X ����Ӧ�����㣺��ɫԪ�أ��Խ����ϣ������� 0 ����ɫԪ�ض��� 0 ��
��ˣ�grid ����һ�� X ����
��ʾ��
n == grid.length == grid[i].length
3 <= n <= 100
0 <= grid[i][j] <= 10^5
*/

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (i == j || i + j == grid.size() - 1)
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (grid[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
};

/*
��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target ���þ�������������ԣ�
ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
ʾ�� 1��
���룺matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
�����true
ʾ�� 2��
���룺matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
�����false
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-10^9 <= matrix[i][j] <= 10^9
ÿ�е�����Ԫ�ش�������������
ÿ�е�����Ԫ�ش��ϵ�����������
-10^9 <= target <= 10^9
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() && !matrix[0].size())
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else if (matrix[i][j] > target)
                j--;
        }
        return false;
    }
};

/*
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
ʾ�� 1��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
�����true
ʾ�� 2��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
�����false
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1])
            {
                int l = 0, r = n - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] < target)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
            }
        }
        return false;
    }
};

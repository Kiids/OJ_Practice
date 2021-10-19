/*
����һ�� n x n ���� matrix ������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е� k С��Ԫ�ء�
��ע�⣬���� ����� �ĵ� k СԪ�أ������ǵ� k �� ��ͬ ��Ԫ�ء�
ʾ�� 1��
���룺matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
�����13
���ͣ������е�Ԫ��Ϊ [1,5,9,10,11,12,13,13,15]���� 8 СԪ���� 13
ʾ�� 2��
���룺matrix = [[-5]], k = 1
�����-5
��ʾ��
n == matrix.length
n == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
��Ŀ���� ��֤ matrix �е������к��ж��� �ǵݼ�˳�� ����
1 <= k <= n^2
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int cnt = fun(matrix, m);
            if (cnt < k)
                l = m + 1;
            else r = m;
        }
        return l;
    }

    int fun(vector<vector<int>>& v, int x)
    {
        int n = v.size(), i = n - 1, j = 0, ret = 0;
        while (i >= 0 && j < n)
        {
            if (v[i][j] <= x)
            {
                ret += i + 1;
                j++;
            }
            else
                i--;
        }
        return ret;
    }
};

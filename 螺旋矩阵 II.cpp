/*
����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��
ʾ�� 1��
���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]
ʾ�� 2��
���룺n = 1
�����[[1]]
��ʾ��
1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0));
		int total = n * n, x = 1, top = 0, bot = n - 1, left = 0, right = n - 1;
		while (x <= total)
		{
			for (int i = left; i <= right; i++)
				v[top][i] = x++;
			top++;

			for (int i = top; i <= bot; i++)
				v[i][right] = x++;
			right--;

			for (int i = right; i >= left; i--)
				v[bot][i] = x++;
			bot--;

			for (int i = bot; i >= top; i--)
				v[i][left] = x++;
			left++;
		}
		return v;
    }
};

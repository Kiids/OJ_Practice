/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：
输入：n = 1
输出：[[1]]
提示：
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

/*
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
返回尽可能高的分数。
示例：
输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
提示：
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1
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
            if (n0 > n1)  // 判断翻转横向还是纵向 
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
        ret = grid.size() * (1 << (grid[0].size() - 1));  // 如果每一行的第一的首元素不为零，则翻转该行，使行首元素置0，此时第0列的数据全为1，求和 
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

// 贪心
// 如果每一行的第一的首元素不为零，则翻转该行，使行首元素置0，此时第0列的数据全为1，
// 然后遍历其他列，使每一列的1的个数尽可能的多些。
// 时间复杂度:O(n*m)


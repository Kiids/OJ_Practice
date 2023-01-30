/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
示例 2：
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
示例 3：
输入：matrix = [[1]]
输出：[[1]]
示例 4：
输入：matrix = [[1,2],[3,4]]
输出：[[3,1],[4,2]]
提示：
matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }
};

// 从外到内一圈一圈进行旋转 
// 每四个为一组进行相应的旋转

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)  // 上下翻转
            matrix[i].swap(matrix[n - 1 - i]);
        for (int i = 0; i < n; i++)      // 主对角线翻转
            for (int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

// 先上下调转，再以斜对角线（左上到右下）为轴对称调转
// 第i行->第n-i-1列
// 第j列->第j行
// 上下调转x[i][j]=x[n-1-i][j]
// 再按斜对角线为轴对称调转x[n-1-i][j]=x[j][n-i-1]

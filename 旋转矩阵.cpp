/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？
示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;
        int l = matrix.size() / 2 - 1;
        int r = (matrix.size() - 1) / 2;
        int n = matrix.size();
        for (int i = l; i >= 0; i--)
        {
            for (int j = r; j >= 0; j--)
            {
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
            }
        }
    }
};

/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出: 16
解释: 它的周长是下面图片中的 16 个黄色的边：
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        for (int row = 0; row <= (int)grid.size() - 1; row++)
        {
            for (int col = 0; col <= (int)grid[0].size() - 1; col++)
            {
                if (grid[row][col])
                {
                    if (0 == row || 0 == grid[row - 1][col]) // 前一个不是
                        ret += 2;

                    if (0 == col || 0 == grid[row][col - 1]) // 上一行不是
                        ret += 2;
                }
            }
        }
        return ret;
    }
};

//因为是一个闭合状态，在北边有一条边，必然在南边的某个地方也有一条边，在西边有一条边，必然在东边也会有一条边，
//这样才能围成闭合图，所以只要求东南或者西南或者东北或者西北方向每次加两次即可 

/*
给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 。
回经过一些翻转后，行与行之间所有值都相等的最大行数。
示例 1：
输入：[[0,1],[1,1]]
输出：1
解释：不进行翻转，有 1 行所有值都相等。
示例 2：
输入：[[0,1],[1,0]]
输出：2
解释：翻转第一列的值之后，这两行都由相等的值组成。
示例 3：
输入：[[0,0,0],[0,0,1],[1,1,0]]
输出：2
解释：翻转前两列的值之后，后两行由相等的值组成。
提示：
1 <= matrix.length <= 300
1 <= matrix[i].length <= 300
所有 matrix[i].length 都相等
matrix[i][j] 为 0 或 1
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        for (auto row : matrix)
        {
            string mode = "";
            if (row[0] == 0)
                for (int x: row)
                    mode += ('0' + x);
            else
                for (int x: row)
                    mode += (x == 0 ? '1' : '0');
            m[mode] ++;
        }

        int ret = 0;
        for (auto [mode, freq] : m)
            ret = max(ret, freq);
        return ret;
    }
};

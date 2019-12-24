// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
// 示例:
// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.resize(numRows);
        for (size_t i = 1; i <= numRows; i++)
        {
            v[i-1].resize(i, 0);
            v[i-1][0] = 1;
            v[i-1][i-1] = 1;
        }
        for (size_t i = 0; i < v.size(); i++)
            for (size_t j = 0; j < v[i].size(); j++)
                if (v[i][j] == 0)
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
        return v;
    }
};


/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：
输入：n = 1, k = 1
输出：[[1]]
提示：
1 <= n <= 20
1 <= k <= n
*/

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> v;
    vector<vector<int>> combine(int n, int k) {
        fun(n, k, k);
        return v;
    }

    void fun(int n, int k, int len){
        if (tmp.size() == len)
        {
            v.push_back(tmp);
            return;
        }
        for (; n >= k; n--) {
            tmp.push_back(n);
            fun(n - 1, k - 1, len);
            tmp.pop_back();
        }
    }
};

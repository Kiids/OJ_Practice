/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：
输入：n = 1
输出：["()"]
提示：
1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int l = 0, r = 0;
        DFS(ret, "", n, l, r);
        return ret;
    }
    void DFS(vector<string>& res, string path, int n, int lc, int rc)
    {
        if (rc > lc || lc > n || rc > n)
            return;
        if (lc == rc && lc == n)
        {
            res.push_back(path);
            return;
        }
        DFS(res, path + '(', n, lc + 1, rc);
        DFS(res, path + ')', n, lc, rc + 1);
    }
};

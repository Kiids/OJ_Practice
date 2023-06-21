/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。
示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：
输入：s = "a"
输出：[["a"]]
提示：
1 <= s.length <= 16
s 仅由小写英文字母组成
*/

class Solution {
    vector<vector<string>> v;
    vector<string> path;
    void DFS(string& s, size_t n, int index)
    {
        if (index >= n)
        {
            v.push_back(path);
            return;
        }
        for (int i = index; i < n; i++)
        {
            int j = index, k = i, flag = 1;
            while (j <= k)
            {
                if (s[j] != s[k])
                {
                    flag = 0;
                    break;
                }
                j++;
                k--;
            }
            if (flag)
            {
                path.push_back(s.substr(index, i - index + 1));
                DFS(s, n, i + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        DFS(s, s.length(), 0);
        return v;
    }
};


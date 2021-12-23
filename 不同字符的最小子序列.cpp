/*
返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
示例 1：
输入：s = "bcabc"
输出："abc"
示例 2：
输入：s = "cbacdcbc"
输出："acdb"
提示：
1 <= s.length <= 1000
s 由小写英文字母组成
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        int st[256];
        unordered_map<char, int> m;
        for (auto c: s)
            m[c]++;
        string ret;
        memset(st, 0, sizeof st);
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]--;
            if (st[s[i]])
                continue;
            while (ret.size() && ret.back() >= s[i] && m[ret.back()])
            {
                st[ret.back()] = false;
                ret.pop_back();
            }
            if (!st[s[i]])
            {
                ret += s[i];
                st[s[i]] = true;
            }
        }
        return ret;
    }
};

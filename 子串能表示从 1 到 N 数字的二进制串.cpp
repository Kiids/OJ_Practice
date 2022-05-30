/*
给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false 。
子字符串 是字符串中连续的字符序列。
示例 1：
输入：s = "0110", n = 3
输出：true
示例 2：
输入：s = "0110", n = 4
输出：false
提示：
1 <= s.length <= 1000
s[i] 不是 '0' 就是 '1'
1 <= n <= 10^9
*/

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> set;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                continue;
            int cur = 0;
            for (int j = i; j < s.size(); j++)
            {
                cur = cur * 2 + s[j] - '0';
                if (cur > n)
                    break;
                set.insert(cur);
            }
        }
        return set.size() == n;
    }
};

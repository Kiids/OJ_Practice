/*
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
示例 1:
输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:
字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。
*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> v(S.size(), 10001);
        for (int i = 0, j = 0; i < S.size(); i++, j++)
            if (S[i] == C) 
                while (j >= 0)
                    v[i - j --] = j;

        for (int i = S.size() - 1, j = 0; i >= 0; i--, j++)
            if (S[i] == C) 
                while (j >= 0)
                    v[i + j --] = min(v[i + j], j);
        return v;
    }
};

/*
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
示例 1：
输入： "()"
输出： 1
示例 2：
输入： "(())"
输出： 2
示例 3：
输入： "()()"
输出： 2
示例 4：
输入： "(()(()))"
输出： 6
提示：
S 是平衡括号字符串，且只含有 ( 和 ) 。
2 <= S.length <= 50
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        return DFS(s) / 2;
    }

    int DFS(string s)
    {
        int i = 0, add = 0;
        while (i < s.size())
        {
            int j = i, n = 1;
            i++;
            while (i < s.size() && n > 0)
            {
                if (s[i] == '(')
                    n++;
                else if (s[i] == ')')
                    n--;
                i++;
            }
            if (i == j + 2)
                add++;
            else
                add += DFS(s.substr(j + 1, i - j - 2));
        }
        return add * 2;
    }
};

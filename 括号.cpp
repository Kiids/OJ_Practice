/*
括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。
说明：解集不能包含重复的子集。
例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        _generateParenthesis(n, n, "");
        return ret;
    }
    void _generateParenthesis(int i, int j, string x)
    {
        if (i == 0 && j == 0)
        {
            ret.push_back(x);
            return;
        }
        if (i != 0)
            _generateParenthesis(i - 1, j, x + '(');
        if (i < j)
            _generateParenthesis(i, j - 1, x + ')');
    }
};

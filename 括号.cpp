/*
���š����һ���㷨����ӡn�����ŵ����кϷ��ģ����磬����һһ��Ӧ����ϡ�
˵�����⼯���ܰ����ظ����Ӽ���
���磬���� n = 3�����ɽ��Ϊ��
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

/*
����һ��ƽ�������ַ��� S�����������������ַ����ķ�����
() �� 1 �֡�
AB �� A + B �֣����� A �� B ��ƽ�������ַ�����
(A) �� 2 * A �֣����� A ��ƽ�������ַ�����
ʾ�� 1��
���룺 "()"
����� 1
ʾ�� 2��
���룺 "(())"
����� 2
ʾ�� 3��
���룺 "()()"
����� 2
ʾ�� 4��
���룺 "(()(()))"
����� 6
��ʾ��
S ��ƽ�������ַ�������ֻ���� ( �� ) ��
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

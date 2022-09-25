/*
����һ���� '('��')' ��Сд��ĸ��ɵ��ַ��� s��
����Ҫ���ַ�����ɾ��������Ŀ�� '(' ���� ')' ������ɾ������λ�õ�����)��ʹ��ʣ�µġ������ַ�������Ч��
�뷵������һ���Ϸ��ַ�����
��Ч�������ַ�����Ӧ���������� ����һ�� Ҫ��
���ַ�����ֻ����Сд��ĸ���ַ���
���Ա�д�� AB��A ���� B�����ַ��������� A �� B ������Ч�������ַ�����
���Ա�д�� (A) ���ַ��������� A ��һ����Ч�ġ������ַ�����
ʾ�� 1��
���룺s = "lee(t(c)o)de)"
�����"lee(t(c)o)de"
���ͣ�"lee(t(co)de)" , "lee(t(c)ode)" Ҳ��һ�����д𰸡�
ʾ�� 2��
���룺s = "a)b(c)d"
�����"ab(c)d"
ʾ�� 3��
���룺s = "))(("
�����""
���ͣ����ַ���Ҳ����Ч��
��ʾ��
1 <= s.length <= 10^5
s[i] ������ '('��')' ��Ӣ��Сд��ĸ
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> left;
        stack<int> right;
        for (int i = 0; i < s.size(); i++)       // ��¼��Ч����λ��
        {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')')
            {
                if (!left.empty())
                    left.pop();
                else
                    right.push(i);
            }
        }
        while (!left.empty() || !right.empty())  // ���
        {
            if (!left.empty())
            {
                s[left.top()] = ' ';
                left.pop();
            }
            if (!right.empty())
            {
                s[right.top()] = ' ';
                right.pop();
            }
        }
        string ret;
        for (char& c : s)
        {
            if (c == ' ')
                continue;
            ret.push_back(c);
        }
        return ret;
    }
};

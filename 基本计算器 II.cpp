/*
����һ���ַ������ʽ s ������ʵ��һ�����������������㲢��������ֵ��
���������������������֡�
����Լ�������ı��ʽ������Ч�ġ������м������� [-2^31, 2^31 - 1] �ķ�Χ�ڡ�
ע�⣺������ʹ���κν��ַ�����Ϊ��ѧ���ʽ��������ú��������� eval() ��
ʾ�� 1��
���룺s = "3+2*2"
�����7
ʾ�� 2��
���룺s = " 3/2 "
�����1
ʾ�� 3��
���룺s = " 3+5 / 2 "
�����5
��ʾ��
1 <= s.length <= 3 * 10^5
s ����������� ('+', '-', '*', '/') ��ɣ��м���һЩ�ո����
s ��ʾһ�� ��Ч���ʽ
���ʽ�е������������ǷǸ����������ڷ�Χ [0, 2^31 - 1] ��
��Ŀ���ݱ�֤����һ�� 32-bit ����
*/

class Solution {
    stack<int> num;  //������
    stack<char> op;  //�����
    void eval() 
    {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        char c = op.top();
        op.pop();
        int r;
        if (c == '+')
            r = a + b;
        else if (c == '-')
            r = a - b;
        else if (c == '*')
            r = a * b;
        else
            r = a / b;
        num.push(r);
    }
public:
    int calculate(string s) {
        s = '0' + s;  // ��ͷ�Ǹ����Ĵ��� 
        unordered_map<char, int> m; 
        m['+'] = m['-'] = 1, m['*'] = m['/'] = 2;  //��������������ȼ�
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i]; 
            if (c == ' ')
                continue;  //�����ո�
            if (isdigit(c))  //c������,��ȡһ������������
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                num.push(x);    //��������ջ��
                i = j - 1;        
            }
            else  //c�ǲ����� 
            {     //opջ�ǿղ���ջ�����������ȼ����ڵ��ڵ�ǰ������c�����ȼ�������eval()����
                while (op.size() && m[op.top()] >= m[c])
                    eval(); 
                op.push(c);
            }
        }
        while (op.size())
            eval(); 
        return num.top();
    }
};

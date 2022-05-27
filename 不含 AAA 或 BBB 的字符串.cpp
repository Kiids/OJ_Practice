/*
������������ a �� b ������ ���� �ַ��� s ��Ҫ�����㣺
s �ĳ���Ϊ a + b�������ð���a �� 'a' ��ĸ�� b �� 'b' ��ĸ��
�Ӵ� 'aaa' û�г����� s �У�
�Ӵ� 'bbb' û�г����� s �С�
ʾ�� 1��
���룺a = 1, b = 2
�����"abb"
���ͣ�"abb", "bab" �� "bba" ������ȷ�𰸡�
ʾ�� 2��
���룺a = 4, b = 1
�����"aabaa"
��ʾ��
0 <= a, b <= 100
���ڸ����� a �� b����֤��������Ҫ��� s 
*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        while (a > 0 || b > 0)
        {
            bool isA = false;
            int len = s.size();
            if (len >= 2 && s[len - 1] == s[len - 2])
                isA = s[len - 1] == 'b';
            else
                isA = a >= b;
            s += isA ? "a" : "b";
            a -= isA;
            b -= !isA;
        }
        return s;
    }
};

/*
����һ�� �� ���ַ� 'a' �� 'b' ��ɵ��ַ���? s ������ַ����� ÿ�� 'a' �������� ÿ�� 'b' ֮ǰ������ true �����򣬷��� false ��
ʾ�� 1��
���룺s = "aaabbb"
�����true
���ͣ�
'a' λ���±� 0��1 �� 2 ���� 'b' λ���±� 3��4 �� 5 ��
��ˣ�ÿ�� 'a' ��������ÿ�� 'b' ֮ǰ�����Է��� true ��
ʾ�� 2��
���룺s = "abab"
�����false
���ͣ�
����һ�� 'a' λ���±� 2 ����һ�� 'b' λ���±� 1 ��
��ˣ���������ÿ�� 'a' ��������ÿ�� 'b' ֮ǰ�����Է��� false ��
ʾ�� 3��
���룺s = "bbb"
�����true
���ͣ�
������ 'a' ����˿�������ÿ�� 'a' ��������ÿ�� 'b' ֮ǰ�����Է��� true ��
��ʾ��
1 <= s.length <= 100
s[i] Ϊ 'a' �� 'b'
*/

class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        for (char& c : s)
        {
            if (c == 'b')
                flag = true;
            else
                if (flag)
                    return false;
        }
        return true;
    }
};

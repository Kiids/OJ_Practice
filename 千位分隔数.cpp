/*
����һ������ n������ÿ����λ��ӵ㣨�� "." ���ţ���Ϊǧλ�ָ���������������ַ�����ʽ���ء�
ʾ�� 1��
���룺n = 987
�����"987"
ʾ�� 2��
���룺n = 1234
�����"1.234"
ʾ�� 3��
���룺n = 123456789
�����"123.456.789"
ʾ�� 4��
���룺n = 0
�����"0"
��ʾ��
0 <= n < 2^31
*/

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0)
            return "0";
        string ret;
        int k = 0;
        while (n > 0)
        {
            if ((k++) % 3 == 0)
                ret += ".";
            ret += '0' + (n % 10);
            n /= 10;
        }
        reverse(ret.begin(), ret.end());
        ret.pop_back();
        return ret;
    }
};

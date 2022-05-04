/*
����һ���Ǹ����� c ����Ҫ�ж��Ƿ������������ a �� b��ʹ�� a^2 + b^2 = c ��
ʾ�� 1��
���룺c = 5
�����true
���ͣ�1 * 1 + 2 * 2 = 5
ʾ�� 2��
���룺c = 3
�����false
��ʾ��
0 <= c <= 2^31 - 1
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while (l <= r)
        {
            if (l * l + r * r == c)
                return true;
            else if (l * l + r * r < c)
                l++;
            else
                r--;
        }
        return false;
    }
};

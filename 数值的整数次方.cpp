/*
ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
ʾ�� 1:
����: 2.00000, 10
���: 1024.00000
ʾ�� 2:
����: 2.10000, 3
���: 9.26100
ʾ�� 3:
����: 2.00000, -2
���: 0.25000
����: 2-2 = 1/22 = 1/4 = 0.25
˵��:
-100.0 < x < 100.0
n �� 32 λ�з�������������ֵ��Χ�� [-2^31, 2^31-1] ��
*/

// ���ַ������� 
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        if (n % 2 == 0)
        {
            double t = myPow(x, n / 2);
            return t * t;
        }
        else
        {
            double t = myPow(x, n / 2);
            if (n < 0)
                x = 1 / x;
            return t * t * x;
        }
    }
};

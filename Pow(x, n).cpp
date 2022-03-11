/*
ʵ�� pow(x, n) �������� x �� n ���ݺ���������x^n ����
ʾ�� 1��
���룺x = 2.00000, n = 10
�����1024.00000
ʾ�� 2��
���룺x = 2.10000, n = 3
�����9.26100
ʾ�� 3��
���룺x = 2.00000, n = -2
�����0.25000
���ͣ�2-2 = 1/22 = 1/4 = 0.25
��ʾ��
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= xn <= 10^4
*/

class Solution {
    double fun(double x, long long n)
    {
        if(n == 0)
            return 1.0;
        double y = fun(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? fun(x, N) : 1.0 / fun(x, - N);
    }
};

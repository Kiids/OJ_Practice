/*
����һ������ n �����������޵��������� [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] ���ҳ������ص� n λ�ϵ����֡�
ʾ�� 1��
���룺n = 3
�����3
ʾ�� 2��
���룺n = 11
�����0
���ͣ��� 11 λ���������� 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... ���� 0 ������ 10 ��һ���֡�
��ʾ��
1 <= n <= 2^31 - 1
*/

class Solution {
public:
    int findNthDigit(int n) {
        long long N = n;
        int digits = 1; // λ�� 
        long long border = 9; // digitsλ��һ����������λ���� 

        while (N)
        {
            if (N <= border * digits)
                break; // ѭ���˳�ʱ���ҵ��˵�ǰ���ֵ�λ��
            N -= border * digits; // N Ϊ�۵�����digitsλ���֣�����2λ��������������֮��ʣ���ٸ�����
            digits++;
            border *= 10;
        }
        // ѭ�������� ʣ���N������ digitsλ�� ���׵�
        // ÿ�� digitsλ�� �������� digits�����֣� ��������������Ϳ���֪��n��Ӧ���ǵڼ���digitsλ��
        int offset = (N - 1) / digits;
        int begin = 1; // ���ڼ�����С�� digitsλ��
        for (int i = 0; i < digits - 1; i++)
            begin *= 10;
        int mod = (N - 1) % digits;
        string target = to_string(offset + begin);
        return target[mod] - '0';
    }
};


class Solution {
public:
    int findNthDigit(long n) {
        int k = 1;
        while (k * pow(10, k) < n)
		{
            n += pow(10, k);
            k += 1;
        }
        return to_string(n / k)[n % k] - '0';
    }
};

// ͨ����0ÿ�������ַ���ȶ����ɵ�ǰλ��k, ��ô���ص� n/k ���� �� �� n%k λ����, ǰ�油0��nҪ���ƶ�Ӧ�ĳ���
// kΪ3ʱ����������Ϊ 000 001 002 003 004 005 006 007 008 009 010 011...
// ǰ�油����λ��ҪѰ�ҵ�n�����ƶ���λ����n += 10 ** k



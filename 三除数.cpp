/*
����һ������ n ����� n ǡ�������������� ������ true �����򣬷��� false ��
����������� k ������ n = k * m ����ô���� m ���� n ��һ�� ���� ��
ʾ�� 1��
���룺n = 2
�����false
���ͣ�2 ֻ������������1 �� 2 ��
ʾ�� 2��
���룺n = 4
�����true
���ͣ�4 ������������1��2 �� 4 ��
��ʾ��
1 <= n <= 10^4
*/

class Solution {
public:
    bool isThree(int n) {
        if (int(sqrt(n)) * int(sqrt(n)) != n)
            return false;
        for (int i = 2; i < n / i; i++)
            if (n % i == 0) 
                return false;
        return n != 1;
    }
};

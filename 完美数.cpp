/*
����һ�� ��������������ͳ������������������ ������ ֮����ȣ����ǳ���Ϊ ������������
����һ�� ���� n�� ����������������� true�����򷵻� false
ʾ�� 1��
���룺28
�����True
���ͣ�28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, �� 14 �� 28 �����������ӡ�
ʾ�� 2��
���룺num = 6
�����true
ʾ�� 3��
���룺num = 496
�����true
ʾ�� 4��
���룺num = 8128
�����true
ʾ�� 5��
���룺num = 2
�����false
��ʾ��
1 <= num <= 108
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
		int sum = 1, i = 2;
		for ( ; i * i < num; i++)
			if (num % i == 0)
                sum += i + num / i;
		if (i * i == num)
            sum += i;
		return sum == num;
    }
};

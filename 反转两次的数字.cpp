/*
��ת һ��������ζ�ŵ�����������λ��
���磬��ת 2021 �õ� 1202 ����ת 12300 �õ� 321 ��������ǰ���� ��
����һ������ num ����ת num �õ� reversed1 �����ŷ�ת reversed1 �õ� reversed2 ����� reversed2 ���� num ������ true �����򣬷��� false ��
ʾ�� 1��
���룺num = 526
�����true
���ͣ���ת num �õ� 625 �����ŷ�ת 625 �õ� 526 ������ num ��
ʾ�� 2��
���룺num = 1800
�����false
���ͣ���ת num �õ� 81 �����ŷ�ת 81 �õ� 18 �������� num �� 
ʾ�� 3��
���룺num = 0
�����true
���ͣ���ת num �õ� 0 �����ŷ�ת 0 �õ� 0 ������ num ��
��ʾ��
0 <= num <= 10^6
*/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num != 0 && num % 10 == 0)
            return false;
        return true;
    }
};

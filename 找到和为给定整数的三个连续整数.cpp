/*
����һ������ num �����㷵���������������������ǵ� �� Ϊ num ����� num �޷�����ʾ���������������ĺͣ����㷵��һ�� �� ���顣
ʾ�� 1��
���룺num = 33
�����[10,11,12]
���ͣ�33 ���Ա�ʾΪ 10 + 11 + 12 = 33 ��
10, 11, 12 �� 3 ���������������Է��� [10, 11, 12] ��
ʾ�� 2��
���룺num = 4
�����[]
���ͣ�û�а취�� 4 ��ʾ�� 3 �����������ĺ͡�
��ʾ��
0 <= num <= 10^15
*/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> v;
        if (num % 3 == 0)
        {
            long long x = num / 3;
            v = vector<long long>{x - 1, x, x + 1};
        }
        return v;
    }
};

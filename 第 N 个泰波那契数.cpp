/*
̩���������� Tn �������£� 
T0 = 0, T1 = 1, T2 = 1, ���� n >= 0 �������� Tn+3 = Tn + Tn+1 + Tn+2
�������� n���뷵�ص� n ��̩�������� Tn ��ֵ��
ʾ�� 1��
���룺n = 4
�����4
���ͣ�
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
ʾ�� 2��
���룺n = 25
�����1389537
��ʾ��
0 <= n <= 37
�𰸱�֤��һ�� 32 λ�������� answer <= 2^31 - 1��
*/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        vector<int> v(n + 1);
        v[0] = 0;
        v[1] = v[2] = 1;
        for (int i = 3; i <= n; i++)
            v[i] = v[i - 1] + v[i - 2] + v[i - 3];
        return v[n];
    }
};

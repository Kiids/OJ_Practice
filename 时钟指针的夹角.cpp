/*
���������� hour �� minutes �����㷵����ʱ���ϣ��ɸ���ʱ���ʱ��ͷ�����ɵĽ�С�ǵĽǶȣ�60 ��λ�ƣ���
ʾ�� 1��
���룺hour = 12, minutes = 30
�����165
ʾ�� 2��
���룺hour = 3, minutes = 30
�����75
ʾ�� 3��
���룺hour = 3, minutes = 15
�����7.5
ʾ�� 4��
���룺hour = 4, minutes = 50
�����155
ʾ�� 5��
���룺hour = 12, minutes = 0
�����0
��ʾ��
1 <= hour <= 12
0 <= minutes <= 59
���׼������� 10^-5 ���ڵĽ��������Ϊ��ȷ�����
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30, m = 6;
        double x = abs((double)minutes * m - ((double)(hour % 12) + (double)minutes / 60) * h);
        return min(x, 360.0 - x);
    }
};

/*
��дһ���������ҳ���������a��b��������һ��������ʹ��if-else�������Ƚ��������
ʾ����
���룺 a = 1, b = 2
����� 2
*/

class Solution {
public:
    int maximum(int a, int b) {
        return (((long)a + (long)b) + abs((long)a - (long)b)) / 2;
    }
};

// ������
class Solution {
public:
    int maximum(int a, int b) {
        long k = (((long)a - (long)b) >> 63) & 1;
        return b * k + a * (k ^ 1);
    }
};
//long������int���ͷ���λ�����ڵ�һλ�ϵģ�long��������63λ�Ϳ����õ�����λ��
//������һ�㣬�������Ƹ�λ��0�����Ǹ������Ƹ�λ��1��
//���a-b<0����ôa-b����λΪ1��k�õ�1.
//����a-b>0����ôa-b����λΪ0����ʱk��ֵΪ0.

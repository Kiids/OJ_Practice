/*
����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��
ʾ��1:
 ���룺A = 29 ������0b11101��, B = 15������0b01111��
 �����2
ʾ��2:
 ���룺A = 1��B = 2
 �����2
��ʾ:
A��B��Χ��[-2147483648, 2147483647]֮��
*/

class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int n = 0, t = A ^ B;  // unsigned int ��ֹ���ָ���ʱ�������� 
        while (t)
        {
            t &= (t - 1);
            n++;
        }
        return n;
    }
};

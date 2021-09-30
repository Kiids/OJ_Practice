/*
������������ left �� right ����ʾ���� [left, right] �����ش��������������� ��λ�� �Ľ�������� left ��right �˵㣩��
ʾ�� 1��
���룺left = 5, right = 7
�����4
ʾ�� 2��
���룺left = 0, right = 0
�����0
ʾ�� 3��
���룺left = 1, right = 2147483647
�����0
��ʾ��
0 <= left <= right <= 2^31 - 1
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 1 << 30, ret = 0;
        while (mask > 0 && (left & mask) == (right & mask))
        {
            ret |= left & mask;
            mask >>= 1;
        }
        return ret;
    }
};

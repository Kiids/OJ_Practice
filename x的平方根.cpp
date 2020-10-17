/*
ʵ�� int sqrt(int x) ������
���㲢���� x ��ƽ���������� x �ǷǸ�������
���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��
ʾ�� 1:
����: 4
���: 2
ʾ�� 2:
����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., 
     ���ڷ���������������С�����ֽ�����ȥ��
*/

class Solution {
public:
    int mySqrt(int x) {
        long l = 1, r = x;
        if (x == 0 || x == 1)
            return x;
            
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (x / mid == mid)
                return mid;
            else if (x / mid > mid)
                l = mid + 1;
            else
                r = mid;
        }
        return l - 1;
    }
};

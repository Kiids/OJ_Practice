/*
����ʾ�����ֵĻ��������ϣ����ǿ���ִ���������ֲ�����
˫����Double��������ʾ���ϵ����ֳ� 2��
�ݼ���Decrement��������ʾ���ϵ����ּ� 1 ��
�������������ʾ���� X��
������ʾ���� Y �������С��������
ʾ�� 1��
���룺X = 2, Y = 3
�����2
���ͣ��Ƚ���˫�����㣬Ȼ���ٽ��еݼ����� {2 -> 4 -> 3}.
ʾ�� 2��
���룺X = 5, Y = 8
�����2
���ͣ��ȵݼ�����˫�� {5 -> 4 -> 8}.
ʾ�� 3��
���룺X = 3, Y = 10
�����3
���ͣ���˫����Ȼ��ݼ�����˫�� {3 -> 6 -> 5 -> 10}.
ʾ�� 4��
���룺X = 1024, Y = 1
�����1023
���ͣ�ִ�еݼ����� 1023 ��
��ʾ��
1 <= X <= 10^9
1 <= Y <= 10^9
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue >= target)
            return startValue - target;
        int x = 0;
        while (startValue < target)
        {
            x++;
            if (target % 2 == 1)
                target++;
            else
                target /= 2;
        }
        return x + startValue - target;
    }
};

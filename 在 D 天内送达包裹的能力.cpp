/*
���ʹ��ϵİ��������� days ���ڴ�һ���ۿ����͵���һ���ۿڡ�
���ʹ��ϵĵ� i ������������Ϊ weights[i]��ÿһ�죬���Ƕ��ᰴ����������weights����˳�������ʹ���װ�ذ���������װ�ص��������ᳬ�������������������
�������� days ���ڽ����ʹ��ϵ����а����ʹ�Ĵ����������������
ʾ�� 1��
���룺weights = [1,2,3,4,5,6,7,8,9,10], days = 5
�����15
���ͣ�
����������� 15 ���ܹ��� 5 �����ʹ����а�����������ʾ��
�� 1 �죺1, 2, 3, 4, 5
�� 2 �죺6, 7
�� 3 �죺8
�� 4 �죺9
�� 5 �죺10
��ע�⣬������밴�ո�����˳��װ�ˣ����ʹ����������Ϊ 14 �Ĵ���������װ�ֳ� (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) �ǲ�����ġ� 
ʾ�� 2��
���룺weights = [3,2,2,4,1,4], days = 3
�����6
���ͣ�
����������� 6 ���ܹ��� 3 �����ʹ����а�����������ʾ��
�� 1 �죺3, 2
�� 2 �죺2, 4
�� 3 �죺1, 4
ʾ�� 3��
���룺weights = [1,2,3,1,1], D = 4
�����3
���ͣ�
�� 1 �죺1
�� 2 �죺2
�� 3 �죺3
�� 4 �죺1, 1
��ʾ��
1 <= days <= weights.length <= 5 * 10^4
1 <= weights[i] <= 500
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, maxNum = 0;
        for (int i = 0; i <weights.size(); i++)
        {
            sum += weights[i];
            maxNum = max(maxNum, weights[i]);
        }
        int low = max(sum / days, maxNum), high = sum, ret = 0;
        while (low <= high)
        {
            int now = (low + high) / 2;
            int tempDay = 1, tempSum = 0;
            for (int i = 0 ; i < weights.size(); i++)
            {
                if (tempSum + weights[i] <= now)
                    tempSum += weights[i];
                else
                {
                    tempDay++;
                    tempSum = weights[i];
                }
            }
            if (tempDay <= days)
            {
                high = now - 1;
                ret = now;
            }
            else
                low = now + 1;
        }
        return ret;
    }
};

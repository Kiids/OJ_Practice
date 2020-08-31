/*
����һ���������� nums �������ѡ������� ���� startValue ��Ϊ��ʼֵ��
����Ҫ�����ұ��� nums ���飬���� startValue �����ۼ��� nums �����е�ֵ��
������ȷ���ۼӺ�ʼ�մ��ڵ��� 1 ��ǰ���£�ѡ��һ����С�� ���� ��Ϊ startValue ��
ʾ�� 1��
���룺nums = [-3,2,-3,4,2]
�����5
���ͣ������ѡ�� startValue = 4���ڵ������ۼ�ʱ����С�� 1 ��
                �ۼ����
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
ʾ�� 2��
���룺nums = [1,2]
�����1
���ͣ���С�� startValue ��Ҫ��������
ʾ�� 3��
���룺nums = [1,-2,-3]
�����5
��ʾ��
1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int total = 0, startValue = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            if (total < startValue)
                startValue = total;
        }
        return startValue < 1   (1 - startValue) : 1;
    }
};

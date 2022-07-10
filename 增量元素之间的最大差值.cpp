/*
����һ���±�� 0 ��ʼ���������� nums ��������Ĵ�СΪ n ��������� nums[j] - nums[i] ����õ� ����ֵ ������ 0 <= i < j < n �� nums[i] < nums[j] ��
���� ����ֵ ���������������Ҫ��� i �� j ������ -1 ��
ʾ�� 1��
���룺nums = [7,1,5,4]
�����4
���ͣ�
����ֵ������ i = 1 �� j = 2 ʱ��nums[j] - nums[i] = 5 - 1 = 4 ��
ע�⣬���� i = 1 �� j = 0 ʱ ��nums[j] - nums[i] = 7 - 1 = 6 > 4 ���� i > j ����������Ҫ������ 6 ������Ч�Ĵ𰸡�
ʾ�� 2��
���룺nums = [9,4,3,2]
�����-1
���ͣ�
������ͬʱ���� i < j �� nums[i] < nums[j] ������������ i, j ��ϡ�
ʾ�� 3��
���룺nums = [1,5,2,10]
�����9
���ͣ�
����ֵ������ i = 0 �� j = 3 ʱ��nums[j] - nums[i] = 10 - 1 = 9 ��
��ʾ��
n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ret = 0, left = 0, right = 1;
        while (right < nums.size())
        {
            if (nums[right] <= nums[left])
            {
                left = right;
                right++;
            }
            else
            {
                ret = max(ret, nums[right] - nums[left]);
                right++;
            }
        }
        if (ret == 0)
            return -1;
        return ret;
    }
};

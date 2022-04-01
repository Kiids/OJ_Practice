/*
����һ���������� nums ���ж�����������Ƿ���ڳ���Ϊ 3 �ĵ��������С�
���������������Ԫ���±� (i, j, k) ������ i < j < k ��ʹ�� nums[i] < nums[j] < nums[k] ������ true �����򣬷��� false ��
ʾ�� 1��
���룺nums = [1,2,3,4,5]
�����true
���ͣ��κ� i < j < k ����Ԫ�鶼��������
ʾ�� 2��
���룺nums = [5,4,3,2,1]
�����false
���ͣ������������������Ԫ��
ʾ�� 3��
���룺nums = [2,1,5,0,4,6]
�����true
���ͣ���Ԫ�� (3, 4, 5) �������⣬��Ϊ nums[3] == 0 < nums[4] == 4 < nums[5] == 6
��ʾ��
1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto num : nums)
        {
            if (num <= small)
            small = num;
            else if (num <= mid)
                mid = num;
            else if (num > mid)
            return true;
        }
        return false;    
    }
};

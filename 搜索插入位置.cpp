/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
ʾ�� 1:
����: [1,3,5,6], 5
���: 2
ʾ�� 2:
����: [1,3,5,6], 2
���: 1
ʾ�� 3:
����: [1,3,5,6], 7
���: 4
ʾ�� 4:
����: [1,3,5,6], 0
���: 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = 0;
        if (target < nums[0]) 
            return 0;
        if (target > nums[r]) 
            return nums.size();
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (target > nums[mid])
                l = mid + 1;
            if (target < nums[mid])
                r = mid - 1;
            if (target == nums[mid])
                return mid;
        }
        return l;
    }
};

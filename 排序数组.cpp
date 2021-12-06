/*
给你一个整数数组 nums，请你将该数组升序排列。
示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
提示：
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        Fun(nums, 0, nums.size() - 1);
        return nums;
    }

    void Fun(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return ;
        int p = Partation(nums, l, r);
        Fun(nums, l, p - 1);
        Fun(nums, p + 1, r);
    }

    int Partation(vector<int>& nums, int l, int r)
    {
        int i = l + rand() % (r - l + 1);
        swap(nums[l], nums[i]);
        int pivot = nums[l];
        while(l < r)
        {
            while (l < r && nums[r] >= pivot)
                r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};

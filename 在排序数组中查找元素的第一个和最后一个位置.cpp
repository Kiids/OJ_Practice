/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);
        ret[0] = -1;
        ret[1] = -1;
        if (nums.size() == 0)
            return ret;
        int i = binarySearch(nums, target);
        if (i == -1)
            return ret;
        int l = i - 1;
        while (l >= 0 && nums[l] == target)
            l--;
        ret[0] = l + 1;
        int r = i + 1;
        while (r < nums.size() && nums[r] == target)
            r++;
        ret[1] = r - 1;
        return ret;
    }
    int binarySearch(vector<int>& n, int x)
    {
        int l = 0, r = n.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (n[mid] == x)
                return mid;
            else if (n[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

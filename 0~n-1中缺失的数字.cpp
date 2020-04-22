/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:
输入: [0,1,3]
输出: 2
示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
限制：
1 <= 数组长度 <= 10000
*/

// 二分查找，如果当前数字与当前位置相等，则说明前面的数字都没有缺失，直接继续对后面的数字进行二分查找
// 无法二分查找的时候，判断l位置的数字是否等于l，等于则+1，不等则-1。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return nums[l] == l ? nums[l] + 1 : nums[l] - 1;
    }
};

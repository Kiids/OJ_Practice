/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
请你找出并返回只出现一次的那个数。
你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
示例 1:
输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:
输入: nums =  [3,3,7,7,10,11,11]
输出: 10
提示:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m < n - 1 && nums[m] == nums[m + 1])
            {
                if ((n - m) & 1)
                    l = m + 2;  // 加2，因为 m + 1 == m 可以直接跳过
                else
                    r = m - 1;
            }
            else if (m > 0 && nums[m] == nums[m - 1])
            {
                if (m & 1)
                    l = m +1 ;
                else
                    r = m - 2;
            }
            else
                return nums[m];
        }
        return 0;
    }
};

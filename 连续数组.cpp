/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
示例 1:
输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
示例 2:
输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
提示：
1 <= nums.length <= 10^5
nums[i] 不是 0 就是 1
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> mp;
        int counter = 0;
        mp[counter] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num == 1)
                counter++;
            else
                counter--;
            if (mp.count(counter))
            {
                int prevIndex = mp[counter];
                maxLength = max(maxLength, i - prevIndex);
            }
            else
                mp[counter] = i;
        }
        return maxLength;
    }
};

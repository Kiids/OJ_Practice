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
        mp[counter] = -1;                                   // 前置值，用于下标从0开始的子数组。
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num == 1)
                counter++;
            else                                            // 把0当作-1处理，这样和为0就是1与0数目相同
                counter--;
            if (mp.count(counter))                          // 如果值已经存在了，保存最靠前的值，从而获得最大长度
            {
                int prevIndex = mp[counter];
                maxLength = max(maxLength, i - prevIndex);  // 更新
            }
            else
                mp[counter] = i;
        }
        return maxLength;
    }
};
// 前缀和哈希表

/*
给你一个 只包含正整数 的 非空 数组?nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
提示：
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        // 背包体积sum/2
        // 物品是sum中的元素，数值等于重量
        // 物品不可以重复放入
        for (int i = 0; i < nums.size(); i++)  // 遍历物品
            for (int j = sum / 2; j >=nums[i] ; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  // 递推公式,nums[i]既是重量又是价值
        if (dp[sum / 2] == sum / 2)
            return true;
        return false;
    }
};

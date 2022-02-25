/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：
输入：nums = [1,2,3]
输出：3
提示：
1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n), dp2(n);
        dp1[1] = nums[0];
        for (int i = 2; i < n; i++)
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);

        dp2[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
            dp2[i] = max(dp2[i + 1], dp2[i + 2] + nums[i + 1]);

        return max(dp1[n - 1], dp2[0]);
    }
};

//选择nums数组的0~nums.length()-2与nums.length()-1~1两部分，分别进行一次动态规划,可以避开nums首尾元素之间的联系

/*
给定一个整数数组，找出总和最大的连续数列，并返回总和。
示例：
输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶：
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

// 动态规划  将原数组当做dp，直接在原数组上改
// 状态： dp[i]表示以i结尾的最大连续子序列
// 状态转移：
// 对于当前的nums[i]
// 如果nums[i] >= 0 则 dp[i] = dp[i-1] + nums[i];
// 否则 dp[i] = nums[i];
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= 0)
                nums[i] += nums[i - 1];
            ret = max(nums[i], ret);
        }
        return ret;
    }
}; 

// 分治法
int maxSubArray(vector<int>& nums)
{
    if (nums.size() == 0) 
		return INT_MIN;
    return divide(nums, 0, nums.size() - 1);
}
int divide(vector<int>& nums, int left, int right)
{
    if (left == right) 
		return nums[left];
    int mid = (left + right) / 2;
    // 1. 最大数列和在左边
    int sumLeft = divide(nums, left, mid);
    // 2. 最大数列和在右边
    int sumRight = divide(nums, mid + 1, right);
    // 3. 最大数列和在中间
    // 先求左边的最大和
    int leftSum = 0, leftMaxSum = INT_MIN;
    for (int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        leftMaxSum = max(leftMaxSum, leftSum);
    }
    // 求右边的最大和
    int rightSum = 0,rightMaxSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        rightMaxSum = max(rightMaxSum, rightSum);
    }
    return max(max(sumLeft, sumRight), leftMaxSum + rightMaxSum);
}


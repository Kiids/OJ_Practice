/*
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
示例 1:
输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:
输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
说明：
1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 2)
            return true;

        int n = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (n == 0)
                    return false;
                if (i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                n--;
            }
        }

        return true;
    }
};

//找到下降点i之后，分三种情况讨论
//cnt已经减为0了，说明是第二个下降点，直接返回false
//nums[i] > nums[i - 2]，修改nums[i-1] = nums[i] (往下拽nums[i-1])
//nums[i] < nums[i - 2]，修改nums[i] = nums[i - 1] (往上拉nums[i])
//如果通过一次以上的上拉或下拽操作能使之有序，则返回true，否则false。

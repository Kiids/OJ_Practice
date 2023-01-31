/*
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）
以这种方式修改数组后，返回数组可能的最大和。
示例 1：
输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
示例 2：
输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
示例 3：
输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
提示：
1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
*/

class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);   // 将数组按照绝对值从大到小排序 
        for (int i = 0; i < nums.size(); i++)  // 从前向后遍历
        {
            if (nums[i] < 0 && k > 0)          // 遇到负数将其变为正数，K--
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1)                        // 如果K大于0，那么反复转变数值最小的元素，将K用完
            nums[nums.size() - 1] *= -1;
        int ret = 0;
        for (int e : nums)                     // 求和
			ret += e; 
        return ret;
    }
};

// 贪心
// 先将数组按照绝对值从大到小排序 遇见负数就取反，若到最后还剩余K的值，则对绝对值最小的数重复操作


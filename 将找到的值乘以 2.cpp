/*
给你一个整数数组 nums ，另给你一个整数 original ，这是需要在 nums 中搜索的第一个数字。
接下来，你需要按下述步骤操作：
如果在 nums 中找到 original ，将 original 乘以 2 ，得到新 original（即，令 original = 2 * original）。
否则，停止这一过程。
只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。
返回 original 的 最终 值。
示例 1：
输入：nums = [5,3,6,1,12], original = 3
输出：24
解释： 
- 3 能在 nums 中找到。3 * 2 = 6 。
- 6 能在 nums 中找到。6 * 2 = 12 。
- 12 能在 nums 中找到。12 * 2 = 24 。
- 24 不能在 nums 中找到。因此，返回 24 。
示例 2：
输入：nums = [2,7,9], original = 4
输出：4
解释：
- 4 不能在 nums 中找到。因此，返回 4 。
提示：
1 <= nums.length <= 1000
1 <= nums[i], original <= 1000
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original))
            original *= 2;
        return original;
    }
};


class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        int mask = 0;
        for (int num : nums)
		{
            if (num % original == 0)
			{
                int k = num / original;  // 倍数
                if ((k & (k - 1)) == 0)  // 倍数是 2 的幂次
                    mask |= k;
            }
        }
        mask = ~mask;  // 取反后，找最低位的 1（lowbit = mask & -mask 补码）
        return original * (mask & -mask);
    }
};

//要找的是 original 的 2 的幂次倍数，因此可以用一个二进制数 mask 记录 nums 中含有哪些 original 的 2 幂次倍数。
//遍历完 nums 后，模拟题目的过程，从 mask 的最低位开始，找连续的 2 的幂次倍数，即连续的 1 的个数。
//可以通过位运算 O(1) 地计算出来：将 mask 取反后，找最低位的 1，其对应的二进制数 lowbit
//即为可以达到的最大 2 的幂次倍数。


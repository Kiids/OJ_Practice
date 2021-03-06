/*
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
示例 1:
输入: k = 5
输出: 9
*/

class Solution {
public:
    int getKthMagicNumber(int k) {
        if (k <= 0)
            return 0;
        
        vector<long long int> nums(k+1, 1);  // 为防止越界，用 long long保存
        int p3 = 0, p5 = 0, p7 = 0;  // 标记"某个素数"的下标
        for (int i = 1; i < k; i++)
        {
            nums[i] = min(min(3 * nums[p3], 5 * nums[p5]), 7 * nums[p7]);
            if (nums[i] == 3 * nums[p3])
                p3++; // p3++是因为由p3所在的素数求得了最小值，故不会再由p3所在的素数求得另一个最小值，下一个最小值可能是3 * nums[p3+1]。下面p5++, p7++同理。
            if (nums[i] == 5 * nums[p5])
                p5++;  // 注意此处是if,而不是else if,因为可能3 *nums[p3] == 5 * nums[p5] 或 7 * nums[p7] == 5 * nums[p5]。下面的同理。
            if (nums[i] == 7 * nums[p7])
                p7++;
        }
        return nums[k-1];
    }
};

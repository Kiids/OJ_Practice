/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
示例 1：
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：
输入：stones = [31,26,33,21,40]
输出：5
示例 3：
输入：stones = [1,2]
输出：1
提示：
1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& e : stones)
            sum += e;

        vector <int> dp(sum + 1);
        for (int i = 0; i < stones.size(); i++)
            for (int j = sum; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
                
        int ret = 0x3f3f3f3f;
        for (int i = 0; i < sum; i++)
            ret = min(ret, abs((sum - dp[i]) - dp[i]));
        return ret;
    }
};

/*
假设现在选取的两个石头 a，b 大小分别为 x 和 y，这时存在两种情况：
a 和 b 相互粉碎，那最后剩余的结果为：abs(a - b) = abs(a + (-b))
a 和 b 加起来一起粉碎更大的石头 c，若 c 的大小为 z，则结果为：abs(c - a - b) = abs(c + (- (a + b)))

背包问题
我们可以把这堆石头分成大小差不多的两堆石头，分别为 sum1 和 sum2，那么答案就为 abs(sum1 - sum2)
我们只需要选取大小和为 sum1 的石头，sum2 就也可以得到：sum - sum1
对于每个石头我们都要选和不选两种情况，对于 a 来说，如果选 a，那么就是 +a，不选就是 +(-a)，
这与上面分析的两种情况对应
我们将背包容量设置为所有石头大小的和 sum，那么最后的结果就是 abs((sum - sum1) - sum1)
定义：dp[i]：背包容量为 i 时能选取的最大石头的大小和
转移方程：dp[i] = max(dp[i], dp[i - stones[i]] + stones[i])
*/


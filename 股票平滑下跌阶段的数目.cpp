/*
给你一个整数数组 prices ，表示一支股票的历史每日股价，其中 prices[i] 是这支股票第 i 天的价格。
一个 平滑下降的阶段 定义为：对于 连续一天或者多天 ，每日股价都比 前一日股价恰好少 1 ，这个阶段第一天的股价没有限制。
请你返回 平滑下降阶段 的数目。
示例 1：
输入：prices = [3,2,1,4]
输出：7
解释：总共有 7 个平滑下降阶段：
[3], [2], [1], [4], [3,2], [2,1] 和 [3,2,1]
注意，仅一天按照定义也是平滑下降阶段。
示例 2：
输入：prices = [8,6,7,7]
输出：4
解释：总共有 4 个连续平滑下降阶段：[8], [6], [7] 和 [7]
由于 8 - 6 ≠ 1 ，所以 [8,6] 不是平滑下降阶段。
示例 3：
输入：prices = [1]
输出：1
解释：总共有 1 个平滑下降阶段：[1]
提示：
1 <= prices.length <= 10^5
1 <= prices[i] <= 10^5
*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size(), ret = 1, len = 1;
        for (int i = 1; i < n; i++)
        {
            len = (prices[i] == prices[i - 1] - 1) ? len + 1 : 1;
            ret += len;
        }
        return ret;
    }
};

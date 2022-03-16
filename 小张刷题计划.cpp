/*
为了提高自己的代码能力，小张制定了 LeetCode 刷题计划，他选中了 LeetCode 题库中的 n 道题，编号从 0 到 n-1，并计划在 m 天内按照题目编号顺序刷完所有的题目（注意，小张不能用多天完成同一题）。
在小张刷题计划中，小张需要用 time[i] 的时间完成编号 i 的题目。此外，小张还可以使用场外求助功能，通过询问他的好朋友小杨题目的解法，可以省去该题的做题时间。为了防止“小张刷题计划”变成“小杨刷题计划”，小张每天最多使用一次求助。
我们定义 m 天中做题时间最多的一天耗时为 T（小杨完成的题目不计入做题总时间）。请你帮小张求出最小的 T是多少。
示例 1：
输入：time = [1,2,3,3], m = 2
输出：3
解释：第一天小张完成前三题，其中第三题找小杨帮忙；第二天完成第四题，并且找小杨帮忙。这样做题时间最多的一天花费了 3 的时间，并且这个值是最小的。
示例 2：
输入：time = [999,999,999], m = 4
输出：0
解释：在前三天中，小张每天求助小杨一次，这样他可以在三天内完成所有的题目并不花任何时间。
限制：
1 <= time.length <= 10^5
1 <= time[i] <= 10000
1 <= m <= 1000
*/

class Solution {
    bool canSplit(vector<int>& time, int m, int split_sum)
    {
        int cnt = 0, sum = 0, maxT = 0;
        for (auto& t : time)
        {
            sum += t;
            maxT = max(maxT, t);
            if (sum - maxT > split_sum)
            {
                if (++cnt == m)
                    return false;
                sum = t;
                maxT = t;
            }
        }
        return true;
    }
public:
    int minTime(vector<int>& time, int m) {
        if (time.size() <= m)
            return 0;
        int l = 0, r = INT_MAX;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (canSplit(time, m, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};

//找到一个数，把它作为分割后各个子数组的和的最大值
//根据这个最大值，分割数组，使每个子数组的和都不超过这个最大值
//	根据题意顺序填充子数组
//使用二分查找来确定这个值
//	int l = 0, int r = INT_MAX; 这个值有可能比单一一个值还大
//	如果不能将数组中所有数字都分割进子数组，则表示这个最大值不够大
//	如果提前分割完了，说明这个值取得太大了

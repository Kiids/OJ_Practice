/*
这里有 n 个航班，它们分别从 1 到 n 进行编号。
有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
示例 1：
输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
解释：
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
示例 2：
输入：bookings = [[1,2,10],[2,2,15]], n = 2
输出：[10,25]
解释：
航班编号        1   2
预订记录 1 ：   10  10
预订记录 2 ：       15
总座位数：      10  25
因此，answer = [10,25]
提示：
1 <= n <= 2 * 10^4
1 <= bookings.length <= 2 * 10^4
bookings[i].length == 3
1 <= firsti <= lasti <= n
1 <= seatsi <= 10^4
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n);
        for (auto& booking: bookings)
        {
            v[booking[0] - 1] += booking[2];
            if (booking[1] < n)
                v[booking[1]] -= booking[2];
        }
        for (int i = 1; i < n; i++)
            v[i] += v[i - 1];
        return v;
    }
};

//每次预定的时候只有两个地方会导致预定位置数发生变化。
//即预定开始的航班，和预定结束的航班号+1的航班。
//开始的地方会导致这个地方增加m个航班，结束的地方不再需要这些位置，所以会减去m个航班。
//差分，实际上是一种数据压缩方式。只记录有变化的位置。
//差分编码。给的原始数据可以认为是差分编码后的数据，本质上是解码。
//用一个数组记录每次预定发生变化的地方。差分的数据如果有重叠，需要叠加。如某两次预定在同一天开始，或者同一天结束。
//最后对差分数据进行积分，得到原始数据。积分在离散的序列里的表现就是前缀和，
//即用一个状态逐次累加序列每个位置的值并记录下来。


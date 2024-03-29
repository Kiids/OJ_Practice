/*
你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
示例 1：
输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出：[20,24]
解释： 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
示例 2：
输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
输出：[1,1]
提示：
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-10^5 <= nums[i][j] <= 10^5
nums[i] 按非递减顺序排列
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); k++)
            for (auto n : nums[k])
                ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> v;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); j++)
        {
            if (!count[ordered[j].second]++)
                k++;
            if (k == nums.size())
            { 
                while (count[ordered[i].second] > 1)
                    count[ordered[i++].second]--; // minialize range
                if (v.empty() || v[1] - v[0] > ordered[j].first - ordered[i].first)
                    v = vector<int>{ordered[i].first, ordered[j].first};
            }
        }
        return v;
    }
};

//首先将 k 组数据升序合并成一组，并记录每个数字所属的组，例如：
//[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
//合并升序后得到：
//[(0, 1), (4, 0), (5, 2), (9, 1), (10, 0), (12, 1), (15, 0), (18, 2), (20, 1), (22, 2), (24, 0), (26, 0), (30, 2)]
//然后只看所属组的话，那么
//[1, 0, 2, 1, 0, 1, 0, 2, 1, 2, 0, 0, 2]
//按组进行滑窗，保证一个窗口的组满足k组后在记录窗口的最小区间值。
//[1 0 2] 2 1 0 1 0 2 1 2 0 0 2    [0, 5]
//1 [0 2 1] 1 0 1 0 2 1 2 0 0 2    [0, 5]
//1 0 [2 1 0] 0 1 0 2 1 2 0 0 2    [0, 5]
//1 0 [2 1 0 1] 1 0 2 1 2 0 0 2    [0, 5]
//1 0 [2 1 0 1 0] 0 2 1 2 0 0 2    [0, 5]
//1 0 2 1 0 [1 0 2] 2 1 2 0 0 2    [0, 5]
//1 0 2 1 0 1 [0 2 1] 1 2 0 0 2    [0, 5]
//1 0 2 1 0 1 [0 2 1 2] 2 0 0 2    [0, 5]
//1 0 2 1 0 1 0 2 [1 2 0] 0 0 2    [20, 24]
//1 0 2 1 0 1 0 2 [1 2 0 0] 0 2    [20, 24]
//1 0 2 1 0 1 0 2 [1 2 0 0 2] 2    [20, 24]


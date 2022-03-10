/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
提示:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
    int n;
    vector<int> v;
    vector<vector<int>> ret;
public:
    void DFS(vector<int>& a, int target, int s)
    {
        if (target == 0)                             // 总和已达到目标数，追加组合数组
        {
            ret.emplace_back(v);
            return;
        }
        for (int i = s; i < n && target - a[i] >= 0; i++)
        {
            if (i != s && a[i] == a[i - 1])          // 当前数与前一数相同跳过
                continue;
            v.emplace_back(a[i]);                    // 组合数组加入当前位置数
            DFS(a, target - a[i], i + 1);            // DFS剩余目标数、下一位置
            v.pop_back();                            // 回溯
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());  // 升序排序
        DFS(candidates, target, 0);
        return ret;
    }
};

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
提示：
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void Backtrack(vector<int>& candidates, int target, int sum, int start)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            Backtrack(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ret.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        Backtrack(candidates, target, 0, 0);
        return ret;
    }
};

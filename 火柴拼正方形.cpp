/*
你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
如果你能使这个正方形，则返回 true ，否则返回 false 。
示例 1:
输入: matchsticks = [1,1,2,2,2]
输出: true
解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:
输入: matchsticks = [3,3,3,3,4]
输出: false
解释: 不能用所有火柴拼成一个正方形。
提示:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 10^8
*/

class Solution {
    bool DFS(int index, vector<int>& matchsticks, int target, vector<int>& bucket)
    {
        //index为当前遍历到的下标，matchsticks为边长数组，target为目标边长，bucket表示当前每条边的长度
        if (index >= matchsticks.size()) // 每条边都用了
            return (bucket[0] == bucket[1]) && (bucket[1] == target) && (bucket[2] == target);
        for (int i = 0; i < 4; i++)
        { // 将当前的边放在4个桶中分别尝试
            if (bucket[i] + matchsticks[index] > target)
                continue; // 说明不可以放在这个边上
            bucket[i] += matchsticks[index]; // 否则放入该边后继续dfs
            if (DFS(index + 1, matchsticks, target, bucket))
                return true;
            bucket[i] -= matchsticks[index]; // 注意回溯的恢复状态
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4)
            return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); 
        // 从大到小排序，优先选用大的边可以令不成功的情况更快返回
        vector<int> bucket(4); // 定义4个边的值
        return DFS(0, matchsticks, sum / 4, bucket);
    }
};

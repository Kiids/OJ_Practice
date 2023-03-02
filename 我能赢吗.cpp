/*
在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100 的玩家，即为胜者。
如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？
例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。
给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家是否能稳赢则返回 true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。
示例 1：
输入：maxChoosableInteger = 10, desiredTotal = 11
输出：false
解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
示例 2:
输入：maxChoosableInteger = 10, desiredTotal = 0
输出：true
示例 3:
输入：maxChoosableInteger = 10, desiredTotal = 1
输出：true
提示:
1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        int state_max = 1 << maxChoosableInteger;
        vector<char> dp(state_max, 0);
        int i, j, k;
        for (i = state_max - 1; i >= 0; i--)
        {
            int total = desiredTotal;
            for (k = 0; k < maxChoosableInteger; k++)
                if ((1 << k) & i)
                    total -= k + 1;
            for (k = 0; k < maxChoosableInteger; k++)
            {
                if ((1 << k) & i)
                    continue;
                if (k + 1 >= total || !dp[(1 << k) | i])  // 玩家游戏时表现最佳是指先手选择一个数字后后手必输，即当前状态的下一个状态为输
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        vector<int> dp(1 << maxChoosableInteger + 1, -1);
        return dfs(dp, maxChoosableInteger, desiredTotal, 0, 0);
    }

    bool dfs(vector<int>& dp, int mci, int dt, int sc, int state) {
        // 当前分数，当前状态, 返回当前玩家能不能赢
        if (dp[state] == -1)
		{
            for (int i = mci, select = 2 << (mci - 1); i >= 1; --i, select >>= 1)
			{
                if ((state & select) == 0)
				{
                    if (sc + i >= dt || !dfs(dp, mci, dt, sc + i, state | select))
					{
                        dp[state] = 1;
                        break;
                    }
                }
            }
            if (dp[state] == -1)
				dp[state] = 0;
        }
        return dp[state] == 1;
    }
};

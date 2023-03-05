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
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)  // 1到maxChoosableInteger的整数和小于desiredTotal，即加起来都不超过的话一定会输 
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
                if (k + 1 >= total || !dp[(1 << k) | i])  // 玩家游戏时表现最佳是指先手选择一个数字后后手必输k + 1 >= total，即当前状态的下一个状态为输!dp[(1 << k) | i]
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
    	// dp[i]-是否赢，mci-可选的最大数字，dt-赢的时候需要达到的数字 
        // sc当前分数，state当前状态, 返回当前玩家能不能赢
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

// 最多可选 20 个数，可以使用一个 int 表示哪些数字选过，哪些数字没选过，然后 dfs 枚举搜索，
// 当数字超过给定的界限或者向下搜索发现对方不能赢，那我就能赢
// dfs(player, score, state)，参数分别表示玩家，分数，和 int 表示的已经选择过的数字的状态，
// 实际上根据最后一个参数状态是可以反推玩家和分数的，所以可以化简为 dfs(state)，仅状态即可。
// 使用记忆化搜索的方法避免重复状态的搜索，此时最多会有 2^20!=1,048,576 种状态，
// 对每一个数字只有已选择和未选择两种可能，共 20 个数字
// 若所有数字累加都达不到要求，那么返回 false

class Solution {
public:
    unordered_map<int, bool> m;  // 记忆化hash，记录选择哪些数的情况当前玩家的胜负，减少时间复杂度
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal)  // 加起来都不能超过的话都不能赢 
            return false;
        return DFS(maxChoosableInteger, 0, desiredTotal, 0);  // 递归判断先手能不能赢，先手从0开始
    }

    bool DFS(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal)
    {
    	// maxChoosableInteger 供选择的数
    	// userNumbers  被选择的数，用二进制表示，0010则表示2已经被选择，0001表示1已被选择
    	// desiredTotal  累计整数合需要超过的目标值
    	// currentTotals  当前累计整数合
        if (!m.count(usedNumbers))  // 未曾判断过这种场景
        {
            bool ret = false;
            for (int i = 0; i < maxChoosableInteger; i++)  // 循环遍历选择每个数的情况，如果循环完所有的情况，都赢不了，就输了，初始ret为输
            {
            	// (userNumbers >> i) & 1 ：判断i+1是否已经被访问 
                if (((usedNumbers >> i) & 1) == 0)  // 若这个数还没被选择，往下继续，否则进入下一轮循环，这里i从0开始，判断的是第i+1个数的情况
                {
                    if (i + 1 + currentTotal >= desiredTotal)  // 如果选完能直接胜利，true
                    {
                        ret = true;
                        break;
                    }
                    // userNumbers | (1 << i)：把i+1标记为访问 
                    if (!DFS(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1))  // 否则递归判断，我选完后，对方选完是不是就输了；对方输了，我就赢了
                    {
                        ret = true;
                        break;
                    }
                }
            }
            m[usedNumbers] = ret;  // 结果放入hashmap 
        }
        return m[usedNumbers];
    }
};


/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
提示：
0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j < dp[0].size(); j++)
            dp[0][j] = j;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp.back().back();
    }
};

//动态规划
//dp[i][j] 代表 word1 中前 i 个字符，变换到 word2 中前 j 个字符，最短需要操作的次数
//考虑 word1 或 word2 一个字母都没有，全增加/删除的情况，预留 dp[0][j] 和 dp[i][0]
//状态转移
//增，dp[i][j] = dp[i][j - 1] + 1
//删，dp[i][j] = dp[i - 1][j] + 1
//改，dp[i][j] = dp[i - 1][j - 1] + 1
//按顺序计算，操作次数加一，取三种最小
//两个字母相同 word1[i - 1] = word2[j - 1] ，直接 dp[i - 1][j - 1]

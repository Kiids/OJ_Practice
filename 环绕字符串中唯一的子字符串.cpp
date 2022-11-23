/*
把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 
现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 
注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。
示例 1:
输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。
示例 2:
输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
示例 3:
输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int k = 1;
        dp[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++)
        {
            if (check(p[i - 1], p[i]))
                k++;
            else
                k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

    bool check(char c, char d)
    {
        if (c == 'z')
            return d == 'a';
        return c + 1 == d;
    }
};

// 记录以每个字符结尾字串的最长长度
// 然后最终累加


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        int count = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (i > 0 && ((p[i - 1] + 1) % 26 == p[i] % 26))
                count++;
            else
                count = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

//动态规划 
//dp[i]：以字符串p[i]结尾的连续字符串的非空子串长度增量.
//p[i]-'a'得到对应dp数组下标
//当 p[i-1] == p[i],count++，与上一个字符构成连续 时： 此情况下最长字符串长度为 dp[p[i]-'a'] = max(dp[p[i]-'a'],count);
//当 p[i-1]!=p[i],count = 1,与上一个字符不连续 时： 此情况下最长字符串长度为 dp[p[i]-'a'] = max(dp[p[i]-'a'],count);。
//转移方程
//dp[p[i]-'a'] = max(dp[p[i]-'a'],count) 。
//初始状态
//i = 0 时 dp[p[i]-'a'] = 1。
//dp[i] 依赖 dp[i-1]，从前向后遍历。
//dp数组求和即结果。
//时间复杂度：O(n)，其中 n 是字符串 p 的长度。
//空间复杂度：O(1)。


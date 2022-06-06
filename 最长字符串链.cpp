/*
给出一个单词数组 words ，其中每个单词都由小写英文字母组成。
如果我们可以 不改变其他字符的顺序 ，在 wordA 的任何地方添加 恰好一个 字母使其变成 wordB ，那么我们认为 wordA 是 wordB 的 前身 。
例如，"abc" 是 "abac" 的 前身 ，而 "cba" 不是 "bcad" 的 前身
词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word1 是 word2 的前身，word2 是 word3 的前身，依此类推。一个单词通常是 k == 1 的 单词链 。
从给定单词列表 words 中选择单词组成词链，返回 词链的 最长可能长度 。
示例 1：
输入：words = ["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 ["a","ba","bda","bdca"]
示例 2:
输入：words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
输出：5
解释：所有的单词都可以放入单词链 ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
示例 3:
输入：words = ["abcd","dbqca"]
输出：1
解释：字链["abcd"]是最长的字链之一。
["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
提示：
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] 仅由小写英文字母组成。
*/

class Solution {
    bool isMatch(const string& a, const string& b)
    {
        if (a.size() != b.size() - 1)
            return false;

        int i = 0;
        for (int j = 0; j < b.size() && i < a.size(); j++)
            if (a[i] == b[j])
                i++;
        return i == a.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){  // 按长度排序
            return a.size() < b.size();
        });

        int n = words.size(), dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1;
            
        int ret = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (isMatch(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

//动态规划
//dp[i]表示以i为结尾的最长的长度
//初始化，至少自己一个单词，初始化 1
//从短到长计算, 对于当前单词找序号比它小的 j 情况： 如果相等，则 max(d[i], dp[j] + 1)
//结果 max(dp[i])


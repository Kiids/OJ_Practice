/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
提示：
1 <= s.length <= 1000
s 由小写英文字母组成
*/

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result += extend(s, i, i, s.size());      // 以i为中心
            result += extend(s, i, i + 1, s.size());  // 以i和i+1为中心
        }
        return result;
    }

    int extend(const string& s, int i, int j, int n) {
        int ret = 0;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            i--;
            j++;
            ret++;
        }
        return ret;
    }
};

//首先确定回文串，找中心然后向两边扩散看是否对称。
//遍历中心点有两种情况。
//一个元素作为中心点，两个元素作为中心点。
//时间复杂度：O(n^2)
//空间复杂度：O(1)

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ret = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
                {
                    ret++;
                    dp[i][j] = true;
                }
            }
        }
        return ret;
    }
};

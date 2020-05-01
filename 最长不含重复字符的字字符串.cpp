/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
提示：
s.length <= 40000
*/

// 滑动窗口 [j ... i]  一维动态规划 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int ret = 1;
        map<char, int> m;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]] == 1)
            {
                if (i - j + 1 > ret)
                    ret = i - j + 1;
                continue;
            }
            if (i == s.size() - 1)
                break;
            while (m[s[i]] > 1)
            {
                m[s[j]]--;
                j++;
            }
        }
        return ret;
    }
};

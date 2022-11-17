/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指字母相同，但排列不同的字符串。
示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
提示:
1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n)
            return {};
        vector<int> v, ns(26), np(26);  // 哈希记录各种字母个数 
        int i;
        for (i = 0; i < m; i++)
        {
            np[p[i] - 'a']++;
            ns[s[i] - 'a']++;
        }
        if (np == ns)
            v.push_back(0);
        for (; i < n; i++)              // 遍历比较 
        {
            ns[s[i] - 'a']++;
            ns[s[i - m] - 'a']--;
            if (np == ns)
                v.push_back(i - m + 1);
        }
        return v;
    }
};

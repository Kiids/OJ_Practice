/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
换句话说，s1 的排列之一是 s2 的 子串 。
示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：
输入：s1= "ab" s2 = "eidboaoo"
输出：false
提示：
1 <= s1.length, s2.length <= 10^4
s1 和 s2 仅包含小写字母
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), k = s1.size();
        unordered_map<char, int> hash;
        for (auto c: s1)
            hash[c] ++ ;
        int cnt = 0, t = hash.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (--hash[s2[i]] == 0)
                cnt++;
            while (i - j + 1 > k)
            {
                if (!hash[s2[j]])
                    cnt--;
                hash[s2[j++]]++ ;
            }
            if (cnt == t)
                return true;
        }
        return false;
    }
};

/*
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
注意：字符串长度 和 k 不会超过?104。
示例 1：
输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
示例 2：
输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() <= 0)
            return 0;
            
        int* v = new int[26];
        memset(v, 0, sizeof(int) * 26);

        int left = 0, maxCharV = 0;
        for (int right = 0; right < s.size(); right++)
        {
            int charInt = s[right]-'A';
            v[charInt]++;
            maxCharV = max(maxCharV, v[charInt]);
            if (right - left + 1 > maxCharV + k)
            {
                v[s[left] - 'A']--;
                left++;
            }
        }
        return s.size() - left;
    }
};

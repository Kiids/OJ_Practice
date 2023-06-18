/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
提示：
1 <= haystack.length, needle.length <= 10^4
haystack 和 needle 仅由小写英文字符组成
*/

class Solution {
    void getNext(int* next, const string& s)  // 填充 next 数组
    {
        int j = 0;
        next[0] = 0;  // 前缀表的首元素 0 ，字符串的首位没有对应的前缀
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        int next[needle.size()];  // 定义 next 数组 - 前缀表
        getNext(next, needle);  // 填充前缀表
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};

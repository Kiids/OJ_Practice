/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
提示：
0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, 0);
        int ret = 0, i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            i = max(i, v[s[j]]);
            v[s[j]] = j + 1;
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};

//滑动窗口，保证每个窗口里字母都是唯一的
//没有重复字符时，调整右边界 j
//但窗口内出现重复字符时，调整左边界 i 
//使用 vector<int> v 来记录一个字母如果后面出现重复时，i 应该调整到的新位置
//每次更新的时候保存 j + 1 ，即字母后面的位置
//j 表示子串的最后一个字母，计算子串长度为 j - i + 1


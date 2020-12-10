/*
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
示例 1：
输入："hello"
输出："holle"
示例 2：
输入："leetcode"
输出："leotcede"
提示：
元音字母不包含字母 "y" 。
*/

class Solution {
public:
    string reverseVowels(string s) {
        string v = "aeiouAEIOU";
        int i = -1, j = s.size();
        while (i < j)
        {
            while (i < j && v.find(s[++i]) == v.npos);
            while (i < j && v.find(s[--j]) == v.npos);
            swap(s[i], s[j]);
        }
        return s;
    }
};

/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。
示例 2:
输入: "aba"
输出: False
示例 3:
输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

//如果 s 中没有循环节，那么 ss 中必然有且只有两个 s，此时从 ss[1] 处开始寻找 s ，必然只能找到第二个，
//所以此时返回值为 s.size()。
//当 s 中有循环节时，设循环节为 r，其长度为 l，那么 ss 中必然有 s.size()/l + 1 个 s。
//因为去掉了第一个 S 的第一个字符 (代码中，(s+s).find(s, 1)， 是从 ss[1] 处开始 find )
//所以此时必回找到第二个 s 的起点。

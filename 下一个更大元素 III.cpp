/*
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
示例 1：
输入：n = 12
输出：21
示例 2：
输入：n = 21
输出：-1
提示：
1 <= n <= 2^31 - 1
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (next_permutation(s.begin(), s.end()) && stoll(s) <= INT_MAX)
            return stoi(s);
        return -1;
    }
};

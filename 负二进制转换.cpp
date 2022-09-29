/*
给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
示例 1：
输入：n = 2
输出："110"
解释：(-2)2 + (-2)1 = 2
示例 2：
输入：n = 3
输出："111"
解释：(-2)2 + (-2)1 + (-2)0 = 3
示例 3：
输入：n = 4
输出："100"
解释：(-2)2 = 4
提示：
0 <= n <= 10^9
*/

class Solution {
    vector<int> baseK(int n, int k)
    {
        if (n == 0)
            return {0};

        vector<int> v;
        while (n != 0)
        {
            int c = ((n % k) + abs(k)) % abs(k);
            v.push_back(c);
            n -= c;
            n /= k;
        }
        reverse(v.begin(), v.end());
        return v;
    }
public:
    string baseNeg2(int n) {
        vector<int> v = baseK(n, -2);
        string s;
        for (auto e : v)
            s += to_string(e);
        return s;
    }
};

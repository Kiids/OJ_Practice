/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
提示：
0 <= num < 231
*/

//递归：递归出口是num是只有一位数，以xyzcba为例，先取最后两位（个位和十位）即ba，如果ba>=26，
//必然不能分解成f(xyzcb)+f(xyzc)，此时只能分解成f(xyzcb);但还有一种情况，就是ba<=9,也就是该数十位上为0，此时也不能分解。
class Solution {
public:
    int translateNum(int num) {
        if (num <= 9)
            return 1;
        int x = num % 100;  // 最后两位
        if (x <= 9 || x >= 26) 
            return translateNum(num / 10);
        else
            return translateNum(num / 10) + translateNum(num / 100);
    }
};

// 动态规划 
//从最后一步出发，最后一步肯定有一个字母，这个字母变成了 0,1，2..,25 ，设字符串的长度为 n ，
//要知道前 n 个字符串翻译方式数，就要知道前 n-1 和前 n-2 翻译方式数，因为最后一个字母可能转换成一位数，
//也可能转换成两位数，即 f[i] = f[i-1] + f[i-2]， i 代表字符串长度
//初始条件
//f[0] = 1   f[0]=1，认为空串也有一种翻译方式
//边界条件
//字符串长度为 1，那只有一种翻译方式
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int dp[11];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.size(); i ++)
        {
            if (s[i - 1] == '0' || s.substr(i - 1, 2) > "25" )
                dp[i + 1] = dp[i];
            else
                dp[i + 1] = dp[i] + dp[i - 1];
        }
        return dp[s.size()];
    }
};

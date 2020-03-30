/*
我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。
输入描述:
输入包含多组数据。
每组数据包含两个字符串m和n，它们仅包含字母，并且长度不超过1024。
输出描述:
对应每组输入，输出最长公共子序列的长度。
示例1
输入
abcfbc abfcab<br/>programming contest<br/>abcd mnp
输出
4<br/>2<br/>0
*/
 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

// 动态规划
int main()
{
    string m, n;
    while (cin >> m >> n)
    {
        int dp[m.size() + 1][n.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= m.size(); i++)
        {
            for (int j = 1; j <= n.size(); j++)
            {
                if (m[i - 1] == n[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        
        cout << dp[m.size()][n.size()] << endl;
    }
    return 0;
}

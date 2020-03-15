/*
求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
输入描述:
每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
输出描述:
输出答案。
示例1
输入
ab ce 1 2
输出
56
*/

#include<iostream>
#include<string>
using namespace std;

int sum(string s)  // 从a开始到s的字符串个数
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)  // 最后一位加和a相差的数目，其余前面几位所跟的下一位可以是a-z共26种
        ret = ret * 26 + s[i] - 'a';
    return ret;
}

int main()
{
    string s1, s2;
    long len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2)
        cout << (sum(s2) - sum(s1) - 1) % 1000007 << endl;  // 减1除去第一个字符串
    return 0;
}

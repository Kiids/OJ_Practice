/*
输入描述:
先输入字典中单词的个数，再输入n个单词作为字典单词。
输入一个单词，查找其在字典中兄弟单词的个数
再输入数字n
输出描述:
根据输入，输出查找到的兄弟单词的个数
示例1
输入
3 abc bca cab abc 1
输出
2
bca
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isBrother(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        if (s1 == s2)
            return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        if (s1 == s2)
            return true;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        
        string str;
        cin >> str;
        int n;
        cin >> n;  // 查找到第n个兄弟单词
        int sum = 0;
        string s2;
        for (int i = 0; i < v.size(); i++)
        {
            if (isBrother(str, v[i]))
            {
                sum++;
                if (sum == n)
                    s2 = v[i];
            }
        }
        cout << sum << endl;
        if (sum >= n)  // 输出查找到的第n个兄弟单词，确定第n个存在
            cout << s2 << endl;
    }
    return 0;
}

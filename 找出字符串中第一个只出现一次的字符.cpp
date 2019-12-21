// 找出字符串中第一个只出现一次的字符
// 输入描述:
// 输入一个非空字符串
// 输出描述:
// 输出第一个只出现一次的字符，如果不存在输出-1
// 示例1
// 输入
// asdfasdfo
// 输出
// o

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int hash[256] = {0}, flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1)
            {
                cout << s[i] << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }
    return 0;
}


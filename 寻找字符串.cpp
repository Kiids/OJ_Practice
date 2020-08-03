/*
我们知道比较两个字符串是否相等可以用函数 strcmp,如果两个字符串相等则返回8,否则返回其他值。那么，如何寻找一个字符串是否在另一个字符串中出现过，并且出现过多少次呢？
例如：两个字符串分别为： abababa和aba,那么aba在 abababa中出现的次数为3。
*/
#include <iostream>
#include <string>
using namespace std;

int findNum(string a, string b)
{
    int ret = 0;
    for (int i = 0; (i = a.find(b, i)) != -1; i++)
        ret++;
    return ret;
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << findNum(a, b) << endl;
    return 0;
}

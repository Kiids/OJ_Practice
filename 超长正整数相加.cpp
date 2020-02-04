/*
请设计一个算法完成两个超长正整数的加法。
接口说明
*/
 /*
 请设计一个算法完成两个超长正整数的加法。
 输入参数：
 String addend：加数
 String augend：被加数
 返回值：加法结果
 *//*
 public String AddLongInteger(String addend, String augend)
 {
     /*在这里实现功能*//*
  return null;     
 }
输入描述:
输入两个字符串数字
输出描述:
输出相加后的结果，string型
示例1
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string AddLongInteger(string addend, string augend)
{
    int l1 = addend.size();
    int l2 = augend.size();

    if (l1 < l2)
    {
        addend.swap(augend);
        swap(l1, l2);
    }

    string ret;
    ret.reserve(l1 + 1);
    char s = 0, r = 0;
    for (int i = 0; i < l1; i++)
    {
        r = addend[l1 - i - 1] - '0' + s;
        s = 0;
        if (i < l2)
            r += augend[l2 - i - 1] - '0';
        if (r >= 10)
        {
            r -= 10;
            s = 1;
        }
        ret += r + '0';
    }
    if (s)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
        cout << AddLongInteger(s1, s2) << endl;
    return 0;
}

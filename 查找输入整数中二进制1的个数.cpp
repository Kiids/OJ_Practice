/*
请实现如下接口
     public   static   int  findNumberOf1( int num)
    {
         /*  请实现  *//*
         return  0;
    } 譬如：输入5 ，5的二进制为101，输出2
涉及知识点：
输入描述:
输入一个整数
输出描述:
计算整数二进制中1的个数
示例1
输入
5
输出
2
*/

#include <iostream>
using namespace std;

int findNumberOf1(int num)
{
    int n = 0;
    for (int i = 0; i < 32; i++)
    {
        if (num & 1 == 1)
            n++;
        num >>= 1;
    }
    return n;
}

int main()
{
    int x, n = 0;
    while (cin >> x)
    {
        cout << findNumberOf1(x) << endl;
    }
    return 0;
}


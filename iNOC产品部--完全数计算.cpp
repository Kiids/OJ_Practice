/*
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1
*/
/**
 * 
 *  完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
 *  它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
 *  例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
 * 
 *  给定函数count(int n),用于计算n以内(含n)完全数的个数
 * @param n  计算范围, 0 < n <= 500000
 * @return n 以内完全数的个数, 异常情况返回-1
 * 
 */    /*
public   static   int  count( int  n)
输入描述:
输入一个数字
输出描述:
输出完全数的个数
示例1
输入
1000
输出
3
*/

#include <iostream>
using namespace std;

bool wanBei(int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++)
    {
        if (x%i == 0)
        {
            sum += i;
        }
    }
    if (sum == x)
        return true;
    else
        return false;
}

int count(int n)
{
    int ret = 0;
    for (int i = 2; i <= n; i++)
    {
        if (wanBei(i))
            ret++;
    }
    return ret;
}

int main()
{
    int x;
    while (cin >> x)
        cout << count(x) << endl;
    return 0;
}

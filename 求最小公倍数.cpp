/*
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入描述:
输入两个正整数A和B。
输出描述:
输出A和B的最小公倍数。
示例1
输入
5 7
输出
35
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B, n;
    cin >> A >> B;
    int max = A>B ? A : B;
    for (n = max; n <= A*B; n++)
    {
        if (n%A == 0 && n%B == 0)
            break;
    }
    cout << n << endl;
    return 0;
}
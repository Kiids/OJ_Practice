/*
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。
输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。
示例1
输入
1<br/>2
输出
1<br/>2
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        long long a[90] = {0};
        a[0] = 1;
        a[1] = 2;
        for (int i = 2; i < 90; i++)
            a[i] = a[i - 1] + a[i - 2];
        cout << a[n - 1] << endl;
    }
    return 0;
}

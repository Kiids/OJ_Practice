/*
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数
输出描述:
输出两个素数
示例1
输入
20
输出
7
13
*/

#include <iostream>
using namespace std;

bool isPrime(int x)
{
	for (int i = 2; i <= x/2; i++)
		if (x % i == 0)
			return false;
	return true;
}
 
int main()
{
    int a;
    while (cin >> a)
    {
        int sub = 0, min = 0, ret = 0;
        for (int i = 2; i <= a/2; i++)
        {
            if (isPrime(i) && isPrime(a - i))
            {
                sub = a - i - i;
                if (min == 0 || min > sub)
                {
                    min = sub;
                    ret = i;
                }
            }
        }
        cout << ret << endl;
        cout << a - ret << endl;
    }

	return 0;
}

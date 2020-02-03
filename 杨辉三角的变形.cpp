/*
           1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
输入n(n <= 1000000000)
输入描述:
输入一个int整数
输出描述:
输出返回的int值
示例1
输入
4
输出
3
*/

#include <iostream>
using namespace std;

int C(int n, int k)
{
    if (k == 1 || k == n*2-1)
        return 1;
    if (k < 1 || k > n*2-1)
        return 0;
    else
        return C(n-1, k-2) + C(n-1, k-1) + C(n-1, k);
}
int main()
{
    int N;
    cin >> N;
    for (int j = 1; j <= 2*N - 1; j++)
    {
        if (C(N, j) % 2 == 0)
        {
            cout << j << endl;
            break;
        }
        else if(j == 2*N - 1)
            cout << "-1" << endl;
    }
}

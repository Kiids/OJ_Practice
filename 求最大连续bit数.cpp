/*
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1  
输入: 一个byte型的数字  
输出: 无   
返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字
输出描述:
输出转成二进制之后连续1的个数
示例1
输入
3
输出
2
*/

#include <iostream>
using namespace std;

int main()
{
    int b, n = 0, max = 0;
    while (cin >> b)
    {
        n = 0;
        max = 0;
        while (b)
        {
            if (b%2 == 0)
                n = 0;
            else
                n++;
            if (n > max)
                max = n;
            b /= 2;
        }
        cout << max << endl;
    }
    return 0;
}

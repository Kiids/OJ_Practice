/*
问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
输出：
true or false
输入描述:
输入4个int整数
输出描述:
返回能否得到24点，能输出true，不能输出false
示例1
输入
7 2 1 10
输出
true
*/

#include <iostream>
#include <vector>
using namespace std;

bool Is24(const vector<double>& a, int total, double result)
{
    if (a.empty())
        return total == result;
    for (int i = 0; i < a.size(); i++)
    {
        vector<double> b(a);
        b.erase(b.begin() + i);
        if (Is24(b, total, result + a[i]) ||
            Is24(b, total, result - a[i]) ||
            Is24(b, total, result * a[i]) ||
            Is24(b, total, result / a[i]))
            return true;
    }
    return false;
}

int main()
{
    vector<double> a(4, 0);
    while (cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        if (Is24(a, 24, 0))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

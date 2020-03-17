/*
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入
5 5
输出
1 4<br/>2 3<br/>5
*/

#include<iostream>
#include<vector>
using namespace std;

// 背包问题 
void fun(int begin, int n, int m, vector<int> v)  // n：1到n个数字  m：背包空间 
{
    if (n == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < v.size(); i++)
            if (i == 0)
                cout << v[i];
            else
                cout << " " << v[i];
        cout << endl;
        return;
    }
    if (m < 0 || begin > n)
        return;
    
    // 选择 
    v.push_back(begin);
    fun(begin + 1, n, m - begin, v);
    
    // 不选择 
    v.pop_back();
    fun(begin + 1, n, m, v);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        fun(1, n, m, v);
    }
    return 0;
}

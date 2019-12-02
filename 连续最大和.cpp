/*
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述:
所有连续子数组中和最大的值。
示例1
输入 
3 -1 2 1
输出
3
*/

#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, max = -1e5;  // 考虑负数情况，max设为很小的数
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        
        if (sum > max)
            max = sum;
        
        if (sum < 0)
            sum = 0;
    }
    cout << max << endl;
    
    return 0;
}
// 只要前面和是正的，就一定会对后面有贡献，每输入一个数判断总和>0
// 限制了max是负数，必须比max大，要是全是负数第一个数比他大，然后赋值为第一个数，判断当前和小于0，下一个重新开始计数，
// 但是因为都是负数所以加起来都不会超过max，也就是第一个负数。

// 法二 
/* 
int main()
{
    int n, sum = 0, max = -1e5;  // 考虑全是负数情况，max取最小数
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (sum > max)
            max = sum;
        
        if (sum < 0)
            sum = 0;
    }
    cout << max << endl;
    return 0;
}
*/

// 以下 
// 运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
// case通过率为90.00% 
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, max = -1e5;  // 考虑负数情况，max设为最小数
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n-1; i++)
    {
        sum = a[i];
        for (int j = i+1; j < n; j++)
        {
            if (max < sum)
                max = sum;
            sum += a[j];
        }
        if (max < sum)
            max = sum;
    }
    cout << max << endl;
    
    return 0;
}

/* 
牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,
牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。
输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
示例1
输入
6
1 2 3 2 2 1
输出
2
*/
 
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> A_i;
    cin >> n;
    A_i.resize(n+1);  // 如果不加这个会发生段错误，数组越界，因为下面比较的是 A_i[i] 与 A_i[i+1] 
    for (int i = 0; i < n; i++)
        cin >> A_i[i];
    
    int i = 0, count = 0;
    while (i < n)
    {
        if (A_i[i] == A_i[i+1])
            i++;
        
        else if (A_i[i] < A_i[i+1])
        {
            while (i < n && A_i[i] < A_i[i+1])
                i++;
            count++;
            i++;
        }
        
        else if (A_i[i] > A_i[i+1])
        {
            while (i < n && A_i[i] > A_i[i+1])
                i++;
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}

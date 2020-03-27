/*
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入
3
7 4 7
2 50
输出
49
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        int k, d;
        cin >> k >> d;
        
        vector<vector<long long>> vmax(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> vmin(n, vector<long long>(k + 1, 0));
        
        // 以第i个人为结尾，选择j个人的最大最小乘积
        for (int i = 0; i < n; i++)
        {
            vmax[i][1] = v[i];
            vmin[i][1] = v[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j <= k; j++)
            {
                for (int m = max(0, i - d); m <= i - 1; m++)
                {
                    vmax[i][j] = max(vmax[i][j], max(vmax[m][j - 1] * v[i], vmin[m][j - 1] * v[i]));
                    vmin[i][j] = min(vmin[i][j], min(vmin[m][j - 1] * v[i], vmax[m][j - 1] * v[i]));
                }
            }
        }
        long long ret = vmax[k - 1][k];
        for (int i = k; i < n; i++)
            ret = max(ret, vmax[i][k]);
        cout << ret << endl;
    }
    return 0;
}

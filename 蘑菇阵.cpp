/*
现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
输入描述:
第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
输出描述:
输出一行，代表所求概率(保留到2位小数)
示例1
输入
2 2 1<br/>2 1<br/>
输出
0.50
*/

//动态规划
// 每个点的概率来源不同，第一行的点，如(1,3)的概率来源只有它左边点(1,2)的1/2，
// 第n行的点如(n,3)，概率来源为(n,2)+(n-1,3)*1/2
// 因为(n,2)只能往右走，概率为1
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int has[25][25];  // 有无蘑菇
double dp[25][25];  // 能够到达每个格子的概率
  
int main(){
    int n, m, k;
    while(cin >> n >> m >> k)
    {
        int i, j;
        memset(has, 0, sizeof(has));
        memset(dp, 0, sizeof(dp));
        int x, y;
        for(i = 0; i < k; i++)
        {
            cin >> x >> y;
            has[x][y] = 1;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = 1;
                    continue;
                }
                if(has[i][j])
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == n && j == m)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    continue;
                }
                if(i == n)
                {
                    dp[i][j] = dp[i-1][j]*0.5 + dp[i][j-1];
                    continue;
                }
                if(j == m)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]*0.5;
                    continue;
                }
                if(i == 1)
                {
                    dp[i][j] = dp[i][j-1]*0.5;
                    continue;
                }
                if(j == 1)
                {
                    dp[i][j] = dp[i-1][j]*0.5;
                    continue;
                }
                dp[i][j] = dp[i][j-1]*0.5 + dp[i-1][j]*0.5;
            }
        }
        cout << fixed << setprecision(2) << dp[n][m] << endl;  // fixed << setprecision(2) 控制小数点后两位
    }
    return 0;
}

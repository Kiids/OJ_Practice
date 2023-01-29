/*
有 A 和 B 两种类型 的汤。一开始每种类型的汤有 n 毫升。有四种分配操作：
提供 100ml 的 汤A 和 0ml 的 汤B 。
提供 75ml 的 汤A 和 25ml 的 汤B 。
提供 50ml 的 汤A 和 50ml 的 汤B 。
提供 25ml 的 汤A 和 75ml 的 汤B 。
当我们把汤分配给某人之后，汤就没有了。每个回合，我们将从四种概率同为 0.25 的操作中进行分配选择。如果汤的剩余量不足以完成某次操作，我们将尽可能分配。当两种类型的汤都分配完时，停止操作。
注意 不存在先分配 100 ml 汤B 的操作。
需要返回的值： 汤A 先分配完的概率 +  汤A和汤B 同时分配完的概率 / 2。返回值在正确答案 10-5 的范围内将被认为是正确的。
示例 1:
输入: n = 50
输出: 0.62500
解释:如果我们选择前两个操作，A 首先将变为空。
对于第三个操作，A 和 B 会同时变为空。
对于第四个操作，B 首先将变为空。
所以 A 变为空的总概率加上 A 和 B 同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
示例 2:
输入: n = 100
输出: 0.71875
提示:
0 <= n <= 10^9
*/

class Solution {
public:
    double soupServings(int n) {
        if (n > 4800)
            return 1;
        n = n % 25 ? n / 25 + 1 : n / 25;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        dp[n][n] = 1;
        int d[4][2] = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
        // 只有A还有剩余的时候才继续分配
        for (int i = n; i > 0; i--)
        {
            for (int j = n; j > 0; j--)
            {
                if (dp[i][j] == 0)
                    continue;
                for (int t = 0; t < 4; t++)
                {
                    int x = max(0 ,i - d[t][0]);
                    int y = max(0, j - d[t][1]);  
                    dp[x][y] += 0.25 * dp[i][j];
                }
            }
        }
        double ret = dp[0][0] / 2;
        for (int i = 1; i <= n; i++)
            ret += dp[0][i];
        return ret;
    }
};
// 自顶向下考虑
// dp[i][j] = 0.25*(dp[i+4][j]+dp[i+3][j+1]+dp[i+2][j+2]+dp[i+1][j+3]);

class Solution {
public:
    double soupServings(int N) {
        // 较大N，直接返回1.0
        if (N >= 4000)
            return 1.0;
        // 归一化
        N = N / 25 + (N % 25 != 0);
        double** d = new double*[N+1];
        for (int i = 0; i <= N; i++)
        {
            d[i] = new double[N + 1];
            memset(d[i], 0, sizeof(double)*(N + 1));
        }
        for (int i = 0; i <= N; i++)
        {
             for (int j = 0; j <= N; j++)
             {
                 if (i > 0 && j > 0)
                     d[i][j] = (d[max(i-4, 0)][j] + d[max(i-3, 0)][max(j-1,0)] + d[max(i-2, 0)][max(j-2,0)] + d[max(i-1, 0)][max(j-3,0)])*0.25;
                 else if (i <= 0 && j <= 0)
                     d[i][j] = 0.5;
                 else if (i <= 0 && j > 0)
                     d[i][j] = 1.0;
             }
        }
        return d[N][N];
    }
};
// dp(i, j) 表示汤 A 和汤 B 剩下 i 和 j 份时，所求的概率值
// 基于 25 的倍数先做一次归一化，变为如下情况
// 4A和0B
// 3A和1B
// 2A和2B
// 1A和3B
// 初始化默认都是0，边缘情况：
// i <= 0, j <= 0: d[i][j] = 1.0 / 2 = 0.5 （同时分配完）
// i <= 0, j > 0: d[i][j] = 1.0 ( 汤A先分配完的概率=1.0)
// i > 0, j <= 0: d[i][j] = 0.0 ( 两种情况都没发生)
// 计算
// d[i][j]= (d[i-4][j] + d[i-3][j-1] + d[i-2][j-2] + d[i-1][j-3])/4.0 (四种概率之和的四分之一)
// 计算避免负值出现，所以要和0取max,计算从小到大, d[N][N] 初始值是N,N就是结果



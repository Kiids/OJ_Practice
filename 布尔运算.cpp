/*
给定一个布尔表达式和一个期望的布尔结果 result，布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成。实现一个函数，算出有几种可使该表达式得出 result 值的括号方法。
示例 1:
输入: s = "1^0|0|1", result = 0
输出: 2
解释:?两种可能的括号方法是
1^(0|(0|1))
1^((0|0)|1)
示例 2:
输入: s = "0&0&0&1^1|0", result = 1
输出: 10
提示：
运算符的数量不超过 19 个
*/

class Solution {
public:
    int countEval(string s, int result) {
        int len=s.size();
        vector<int> A;
        vector<char> opt;
        for (int i = 0; i < len; i++)
            if (i&1)
                opt.push_back(s[i]);
            else
                A.push_back(s[i]-'0');
        int n = A.size();
        int F[n][n][2];
        for (int i = 0; i < n; i++)
            F[i][i][A[i]]=1,F[i][i][A[i]^1]=0;
        for (int l=2;l<=n;++l)
        {
            for (int i=0;i+l-1<n;++i)
            {
                int j=i+l-1;
                F[i][j][0]=F[i][j][1]=0;
                for (int k=i;k<j;++k)
                    if (opt[k]=='&')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else if (opt[k]=='|')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else
                    {
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
            }
        }
        return F[0][n-1][result];
    }
};

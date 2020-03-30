/*
�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�
��������:
��������������ݡ�
ÿ�����ݰ��������ַ���m��n�����ǽ�������ĸ�����ҳ��Ȳ�����1024��
�������:
��Ӧÿ�����룬�������������еĳ��ȡ�
ʾ��1
����
abcfbc abfcab<br/>programming contest<br/>abcd mnp
���
4<br/>2<br/>0
*/
 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

// ��̬�滮
int main()
{
    string m, n;
    while (cin >> m >> n)
    {
        int dp[m.size() + 1][n.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= m.size(); i++)
        {
            for (int j = 1; j <= n.size(); j++)
            {
                if (m[i - 1] == n[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        
        cout << dp[m.size()][n.size()] << endl;
    }
    return 0;
}

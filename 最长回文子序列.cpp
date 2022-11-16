/*
����һ���ַ��� s ���ҳ�������Ļ��������У������ظ����еĳ��ȡ�
�����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�
ʾ�� 1��
���룺s = "bbbab"
�����4
���ͣ�һ�����ܵ������������Ϊ "bbbb" ��
ʾ�� 2��
���룺s = "cbbd"
�����2
���ͣ�һ�����ܵ������������Ϊ "bb" ��
��ʾ��
1 <= s.length <= 1000
s ����СдӢ����ĸ���
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        int dp[n][n];                // dp[i][j] -> j - i �����ڵ�����ĳ���
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)  // ��ʼ�� һ����ĸ����Ϊ���� 1 �Ļ��Ĵ� 
            dp[i][i] = 1;
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                dp[i][j] = s[i] == s[j] ? dp[i - 1][j + 1] + 2 : max(dp[i - 1][j], dp[i][j + 1]);
        return dp[n - 1][0];
    }
};

/*
���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ���� ��ɵġ�
�����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ� ���ַ�����
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
��ʾ��a + b ��ζ���ַ��� a �� b ���ӡ�
ʾ�� 1��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
�����true
ʾ�� 2��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
�����false
ʾ�� 3��
���룺s1 = "", s2 = "", s3 = ""
�����true
��ʾ��
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1��s2���� s3 ����СдӢ����ĸ���
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if (a + b != c)
            return false;

        bool dp[a + 1][b + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < a + 1; i++)
            for (int j = 0; j < b + 1; j++)
            {
                if (0 <= i - 1 && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i - 1][j];
                if (0 <= j - 1 && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        return dp[a][b];
    }
};

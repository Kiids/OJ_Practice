/*
������������ word1 �� word2�� �뷵�ؽ� word1 ת���� word2 ��ʹ�õ����ٲ�����  ��
����Զ�һ�����ʽ����������ֲ�����
����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
ʾ�� 1��
���룺word1 = "horse", word2 = "ros"
�����3
���ͣ�
horse -> rorse (�� 'h' �滻Ϊ 'r')
rorse -> rose (ɾ�� 'r')
rose -> ros (ɾ�� 'e')
ʾ�� 2��
���룺word1 = "intention", word2 = "execution"
�����5
���ͣ�
intention -> inention (ɾ�� 't')
inention -> enention (�� 'i' �滻Ϊ 'e')
enention -> exention (�� 'n' �滻Ϊ 'x')
exention -> exection (�� 'n' �滻Ϊ 'c')
exection -> execution (���� 'u')
��ʾ��
0 <= word1.length, word2.length <= 500
word1 �� word2 ��СдӢ����ĸ���
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j < dp[0].size(); j++)
            dp[0][j] = j;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp.back().back();
    }
};

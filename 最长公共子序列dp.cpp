/*
���������ַ��� text1 �� text2�������������ַ������ ���������� �ĳ��ȡ���������� ���������� ������ 0 ��
һ���ַ����� ������ ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
�����ַ����� ���������� ���������ַ�������ͬӵ�е������С�
ʾ�� 1��
���룺text1 = "abcde", text2 = "ace" 
�����3  
���ͣ�������������� "ace" �����ĳ���Ϊ 3 ��
ʾ�� 2��
���룺text1 = "abc", text2 = "abc"
�����3
���ͣ�������������� "abc" �����ĳ���Ϊ 3 ��
ʾ�� 3��
���룺text1 = "abc", text2 = "def"
�����0
���ͣ������ַ���û�й��������У����� 0 ��
��ʾ��
1 <= text1.length, text2.length <= 1000
text1 �� text2 ����СдӢ���ַ���ɡ�
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1));
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }   
        }
        return dp[text1.size()][text2.size()];
    }
};

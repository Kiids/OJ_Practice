/*
С�۳�ȥ���Σ�;���ռ���һЩ��Ҷ�ͻ�Ҷ����������ЩҶ�ӳ���������һ����Ҷ�ղؼ� leaves�� �ַ��� leaves ������Сд�ַ� r �� y�� �����ַ� r ��ʾһƬ��Ҷ���ַ� y ��ʾһƬ��Ҷ��
������������Ŀ��ǣ�С����Ҫ���ղؼ�����Ҷ�����е����ɡ��졢�ơ��졹�����֡�ÿ������Ҷ�������Բ���ȣ���������ڵ��� 1��ÿ�ε���������С�ۿ��Խ�һƬ��Ҷ�滻�ɻ�Ҷ���߽�һƬ��Ҷ�滻�ɺ�Ҷ������С��������Ҫ���ٴε����������ܽ���Ҷ�ղؼ�������ϡ�
ʾ�� 1��
���룺leaves = "rrryyyrryyyrr"
�����2
���ͣ��������Σ����м����Ƭ��Ҷ�滻�ɻ�Ҷ���õ� "rrryyyyyyyyrr"
ʾ�� 2��
���룺leaves = "ryr"
�����0
���ͣ��ѷ���Ҫ�󣬲���Ҫ�������
��ʾ��
3 <= leaves.length <= 10^5
leaves ��ֻ�����ַ� 'r' ���ַ� 'y'
*/

class Solution {
public:
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(3, vector<int>(leaves.size(), 0));
        for (int i = 0; i < leaves.size(); i++)
        {
            if (i < 1)
                dp[0][i] = (leaves[i] != 'r');
            else
                dp[0][i] = dp[0][i - 1] + (leaves[i] != 'r');
            
            if (i < 1)
                dp[1][i] = dp[0][i];
            else 
                dp[1][i] = min(dp[0][i - 1] + (leaves[i] != 'y'), dp[1][i - 1] + (leaves[i] != 'y'));

            if (i < 2)
                dp[2][i] = dp[1][i];
            else
                dp[2][i] = min(dp[1][i - 1] + (leaves[i] != 'r'), dp[2][i - 1] + (leaves[i] != 'r'));
        }
        return dp[2].back();
    }
};

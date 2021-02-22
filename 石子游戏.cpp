/*
������˹�����ü���ʯ��������Ϸ��ż����ʯ���ų�һ�У�ÿ�Ѷ�����������ʯ�� piles[i] ��
��Ϸ��˭���е�ʯ�����������ʤ����ʯ�ӵ�����������������û��ƽ�֡�
������˹�����������У�������˹�ȿ�ʼ�� ÿ�غϣ���Ҵ��еĿ�ʼ�������ȡ������ʯͷ�� �������һֱ������û�и����ʯ�Ӷ�Ϊֹ����ʱ����ʯ��������һ�ʤ��
����������˹������ӳ����ˮƽ����������˹Ӯ�ñ���ʱ���� true ������Ӯ�ñ���ʱ���� false ��
ʾ����
���룺[5,3,4,5]
�����true
���ͣ�
������˹�ȿ�ʼ��ֻ����ǰ 5 �Ż�� 5 ��ʯ�� ��
������ȡ��ǰ 5 �ţ���һ�оͱ���� [3,4,5] ��
���������ǰ 3 �ţ���ôʣ�µ��� [4,5]��������˹���ߺ� 5 ��Ӯ�� 10 �֡�
��������ߺ� 5 �ţ���ôʣ�µ��� [3,4]��������˹���ߺ� 4 ��Ӯ�� 9 �֡�
�������ȡǰ 5 ��ʯ�Ӷ�������˹��˵��һ��ʤ���ľٶ����������Ƿ��� true ��
��ʾ��
2 <= piles.length <= 500
piles.length ��ż����
1 <= piles[i] <= 500
sum(piles) ��������
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n =piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int sum = 0;
        for (auto& num : piles)
            sum += num; 
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((j - i) % 2 == 0)
                    continue;
                int tmp = max(piles[i], piles[j]);
                if (j - i == 1)
                    dp[i][j] = tmp;
                else if (i == n - 2)
                     dp[i][j] = max(dp[i + 1][j - 1] + tmp, dp[i][j - 2] + piles[j]);
                else if (j == 1)
                    dp[i][j] = max(dp[i + 1][j - 1] + tmp, dp[i + 2][j] + piles[i]);
                else
                    dp[i][j] = max(dp[i + 1][j - 1] + tmp, max(dp[i + 2][j] + piles[i], dp[i][j - 2] + piles[j]));
            }
        }
        return dp[0][n - 1] > (sum - dp[0][n - 1]);
    }
};

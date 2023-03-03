/*
�� "100 game" �����Ϸ�У������������ѡ��� 1 �� 10 �������������ۼ������ͣ���ʹ���ۼ������� �ﵽ�򳬹�  100 ����ң���Ϊʤ�ߡ�
������ǽ���Ϸ�����Ϊ ����� ���� �ظ�ʹ�������� �أ�
���磬������ҿ��������ӹ����������г�ȡ�� 1 �� 15 �����������Żأ���ֱ���ۼ������� >= 100��
������������ maxChoosableInteger ���������п�ѡ������������ desiredTotal���ۼƺͣ������ȳ��ֵ�����Ƿ�����Ӯ�򷵻� true �����򷵻� false ��������λ�����Ϸʱ������ ��� ��
ʾ�� 1��
���룺maxChoosableInteger = 10, desiredTotal = 11
�����false
���ͣ�
���۵�һ�����ѡ���ĸ�������������ʧ�ܡ�
��һ����ҿ���ѡ��� 1 �� 10 ��������
�����һ�����ѡ�� 1����ô�ڶ������ֻ��ѡ��� 2 �� 10 ��������
�ڶ�����ҿ���ͨ��ѡ������ 10����ô�ۻ���Ϊ 11 >= desiredTotal�����Ӷ�ȡ��ʤ��.
ͬ���أ���һ�����ѡ�����������������ڶ�����Ҷ���Ӯ��
ʾ�� 2:
���룺maxChoosableInteger = 10, desiredTotal = 0
�����true
ʾ�� 3:
���룺maxChoosableInteger = 10, desiredTotal = 1
�����true
��ʾ:
1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)  // 1��maxChoosableInteger��������С��desiredTotal 
            return false;
        int state_max = 1 << maxChoosableInteger;
        vector<char> dp(state_max, 0);
        int i, j, k;
        for (i = state_max - 1; i >= 0; i--)
        {
            int total = desiredTotal;
            for (k = 0; k < maxChoosableInteger; k++)
                if ((1 << k) & i)
                    total -= k + 1;
            for (k = 0; k < maxChoosableInteger; k++)
            {
                if ((1 << k) & i)
                    continue;
                if (k + 1 >= total || !dp[(1 << k) | i])  // �����Ϸʱ���������ָ����ѡ��һ�����ֺ���ֱ��䣬����ǰ״̬����һ��״̬Ϊ��
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        vector<int> dp(1 << maxChoosableInteger + 1, -1);
        return dfs(dp, maxChoosableInteger, desiredTotal, 0, 0);
    }

    bool dfs(vector<int>& dp, int mci, int dt, int sc, int state) {
        // ��ǰ��������ǰ״̬, ���ص�ǰ����ܲ���Ӯ
        if (dp[state] == -1)
		{
            for (int i = mci, select = 2 << (mci - 1); i >= 1; --i, select >>= 1)
			{
                if ((state & select) == 0)
				{
                    if (sc + i >= dt || !dfs(dp, mci, dt, sc + i, state | select))
					{
                        dp[state] = 1;
                        break;
                    }
                }
            }
            if (dp[state] == -1)
				dp[state] = 0;
        }
        return dp[state] == 1;
    }
};

//����ѡ 20 ����������ʹ��һ�� int ��ʾ��Щ����ѡ������Щ����ûѡ����Ȼ�� dfs ö��������
//�����ֳ��������Ľ��޻��������������ֶԷ�����Ӯ�����Ҿ���Ӯ
//dfs(player, score, state)�������ֱ��ʾ��ң��������� int ��ʾ���Ѿ�ѡ��������ֵ�״̬��
//ʵ���ϸ������һ������״̬�ǿ��Է�����Һͷ����ģ����Կ��Ի���Ϊ dfs(state)����״̬���ɡ�
//ʹ�ü��仯�����ķ��������ظ�״̬����������ʱ������ 2^20!=1,048,576 ��״̬��
//��ÿһ������ֻ����ѡ���δѡ�����ֿ��ܣ��� 20 ������
//�����������ۼӶ��ﲻ��Ҫ����ô���� false


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
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)  // 1��maxChoosableInteger��������С��desiredTotal�������������������Ļ�һ������ 
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
                if (k + 1 >= total || !dp[(1 << k) | i])  // �����Ϸʱ���������ָ����ѡ��һ�����ֺ���ֱ���k + 1 >= total������ǰ״̬����һ��״̬Ϊ��!dp[(1 << k) | i]
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
    	// dp[i]-�Ƿ�Ӯ��mci-��ѡ��������֣�dt-Ӯ��ʱ����Ҫ�ﵽ������ 
        // sc��ǰ������state��ǰ״̬, ���ص�ǰ����ܲ���Ӯ
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

// ����ѡ 20 ����������ʹ��һ�� int ��ʾ��Щ����ѡ������Щ����ûѡ����Ȼ�� dfs ö��������
// �����ֳ��������Ľ��޻��������������ֶԷ�����Ӯ�����Ҿ���Ӯ
// dfs(player, score, state)�������ֱ��ʾ��ң��������� int ��ʾ���Ѿ�ѡ��������ֵ�״̬��
// ʵ���ϸ������һ������״̬�ǿ��Է�����Һͷ����ģ����Կ��Ի���Ϊ dfs(state)����״̬���ɡ�
// ʹ�ü��仯�����ķ��������ظ�״̬����������ʱ������ 2^20!=1,048,576 ��״̬��
// ��ÿһ������ֻ����ѡ���δѡ�����ֿ��ܣ��� 20 ������
// �����������ۼӶ��ﲻ��Ҫ����ô���� false

class Solution {
public:
    unordered_map<int, bool> m;  // ���仯hash����¼ѡ����Щ���������ǰ��ҵ�ʤ��������ʱ�临�Ӷ�
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal)  // �����������ܳ����Ļ�������Ӯ 
            return false;
        return DFS(maxChoosableInteger, 0, desiredTotal, 0);  // �ݹ��ж������ܲ���Ӯ�����ִ�0��ʼ
    }

    bool DFS(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal)
    {
    	// maxChoosableInteger ��ѡ�����
    	// userNumbers  ��ѡ��������ö����Ʊ�ʾ��0010���ʾ2�Ѿ���ѡ��0001��ʾ1�ѱ�ѡ��
    	// desiredTotal  �ۼ���������Ҫ������Ŀ��ֵ
    	// currentTotals  ��ǰ�ۼ�������
        if (!m.count(usedNumbers))  // δ���жϹ����ֳ���
        {
            bool ret = false;
            for (int i = 0; i < maxChoosableInteger; i++)  // ѭ������ѡ��ÿ��������������ѭ�������е��������Ӯ���ˣ������ˣ���ʼretΪ��
            {
            	// (userNumbers >> i) & 1 ���ж�i+1�Ƿ��Ѿ������� 
                if (((usedNumbers >> i) & 1) == 0)  // ���������û��ѡ�����¼��������������һ��ѭ��������i��0��ʼ���жϵ��ǵ�i+1���������
                {
                    if (i + 1 + currentTotal >= desiredTotal)  // ���ѡ����ֱ��ʤ����true
                    {
                        ret = true;
                        break;
                    }
                    // userNumbers | (1 << i)����i+1���Ϊ���� 
                    if (!DFS(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1))  // ����ݹ��жϣ���ѡ��󣬶Է�ѡ���ǲ��Ǿ����ˣ��Է����ˣ��Ҿ�Ӯ��
                    {
                        ret = true;
                        break;
                    }
                }
            }
            m[usedNumbers] = ret;  // �������hashmap 
        }
        return m[usedNumbers];
    }
};


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
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
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
                if (k + 1 >= total || !dp[(1 << k) | i])
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};

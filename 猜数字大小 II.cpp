/*
����������һ��������Ϸ����Ϸ�������£�
�Ҵ� 1 �� n ֮��ѡ��һ�����֣���������ѡ���ĸ����֡�
ÿ����´��ˣ��Ҷ�������㣬��ѡ�����ֱ���Ĵ��˻���С�ˡ�
Ȼ��������������� x ���Ҳ´��˵�ʱ������Ҫ֧�����Ϊ x ���ֽ�ֱ����µ���ѡ�����֣������Ӯ���������Ϸ��
ʾ��:
n = 10, ��ѡ����8.
��һ��: �����ѡ���������5���һ�����㣬�ҵ����ָ���һЩ��Ȼ������Ҫ֧��5�顣
�ڶ���: �����7���Ҹ����㣬�ҵ����ָ���һЩ����֧��7�顣
������: �����9���Ҹ����㣬�ҵ����ָ�СһЩ����֧��9�顣
��Ϸ������8 ������ѡ�����֡�
������Ҫ֧�� 5 + 7 + 9 = 21 ��Ǯ��
���� n �� 1��������������Ҫӵ�ж����ֽ����ȷ������Ӯ�������Ϸ��
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int l = 2; l <= n; l++)              // ���䳤��
        {
            for (int i = 1; i <= n - l + 1; i++)  // �������
            {
                int j = i + l - 1;
                int x = INT_MAX;
                for (int k = i; k < j; k++)
                    x = min(x, k + max(dp[i][k - 1], dp[k + 1][j]));
                dp[i][j] = x;
            }
        }
        return dp[1][n];
    }
};

// dp[i][j] Ϊѡ�������������[i,j]���������С�ֽ�����
// ���� dp[i][j] ����ѡ��ĵ����� k��[i,j]��
// ת�Ʒ��̣�
// dp[i][j] = min{i��k��j} {k + max(dp[i][k-1],dp[k+1][j])
// ���䳤�ȴ��״̬��Ҫ�������䳤��С��״̬ת�ƶ�����
// ��һ��forö������ĳ��ȣ��ڶ���forö����������(��˵�)��
// ��������ĳ��Ⱥ����(��˵�)������������յ�(�Ҷ˵�)�������� for ö�ٲµ����֣����ֽ�㡣
// ��ʼ���߽�
// ʱ�临�Ӷȣ�O(n^3)
// �ռ临�Ӷȣ�O(n^2)


class Solution {
    int v[201][201];
    int DFS(int left, int right)
    {
        if (left >= right)
            return 0; 
        if (v[left][right] != 0)
            return v[left][right];

        int ret = INT_MAX;
        for (int val = left; val <= right; val++)
        {
            int sub_left = DFS(left, val - 1);
            int sub_right = DFS(val + 1, right);
            int max_sub = max(sub_left, sub_right) + val;
            ret = min(ret, max_sub);
        }
        v[left][right] = ret;
        return ret;
    }
public:
    int getMoneyAmount(int n) {
        return DFS(1, n);
    }
};

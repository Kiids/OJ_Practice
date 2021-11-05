/*
���� n �����ԡ� ��ÿһ�������У���һ���������Ǳȵڶ�������С��
���ڣ����Ƕ���һ�ָ����ϵ�����ҽ��� b < c ʱ������(c, d) �ſ��Ը��� (a, b) ���档������������ʽ������һ����������
����һ�����Լ��ϣ��ҳ��ܹ��γɵ���������ĳ��ȡ��㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣
ʾ����
���룺[[1,2], [2,3], [3,4]]
�����2
���ͣ������������ [1,2] -> [3,4]
��ʾ��
�������Եĸ����� [1, 1000] ��Χ�ڡ�
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int>b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int ret = 1;
        vector<int> dp(pairs.size(), 1);
        for (int i = 1; i < pairs.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

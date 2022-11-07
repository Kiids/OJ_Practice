/*
����һ���������� arr ������ arr �� �������������ĳ��� ��
����ȽϷ������������е�ÿ������Ԫ�ض�֮�䷭ת������������� ���������� ��
����ʽ����˵���� arr �������� A[i], A[i+1], ..., A[j] �����������������ʱ�����ǳ���Ϊ���������飺
�� i <= k < j ��
�� k Ϊ����ʱ�� A[k] > A[k+1]����
�� k Ϊż��ʱ��A[k] < A[k+1]��
�� �� i <= k < j ��
�� k Ϊż��ʱ��A[k] > A[k+1] ����
�� k Ϊ����ʱ�� A[k] < A[k+1]��
ʾ�� 1��
���룺arr = [9,4,2,10,7,8,8,1,9]
�����5
���ͣ�arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
ʾ�� 2��
���룺arr = [4,8,12,16]
�����2
ʾ�� 3��
���룺arr = [100]
�����1
��ʾ��
1 <= arr.length <= 4 * 10^4
0 <= arr[i] <= 10^9
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 1));
        int ret = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
                dp[i][0] = dp[i - 1][1] + 1;
            else if (arr[i] < arr[i - 1])
                dp[i][1] = dp[i - 1][0] + 1;
            else
                continue;
            ret = max(ret, max(dp[i][1], dp[i][0]));
        }
        return ret;
    }
};

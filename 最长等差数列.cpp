/*
����һ���������� nums������ nums ����Ȳ������еĳ��ȡ�
����һ�£�nums ����������һ���б� nums[i1], nums[i2], ..., nums[ik] ���� 0 <= i1 < i2 < ... < ik <= nums.length - 1��������� seq[i+1] - seq[i]( 0 <= i < seq.length - 1) ��ֵ����ͬ����ô���� seq �ǵȲ�ġ�
ʾ�� 1��
���룺nums = [3,6,9,12]
�����4
���ͣ� 
���������ǹ���Ϊ 3 �ĵȲ����С�
ʾ�� 2��
���룺nums = [9,4,7,2,10]
�����3
���ͣ�
��ĵȲ��������� [4,7,10]��
ʾ�� 3��
���룺nums = [20,1,15,3,10,5,8]
�����4
���ͣ�
��ĵȲ��������� [20,15,10,5]��
��ʾ��
2 <= nums.length <= 1000
0 <= nums[i] <= 500
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
            
        vector<vector<int>> dp(n, vector<int>(1001));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ret = max(ret, dp[i][diff]);
            }
        }
        return ret + 1;
    }
};

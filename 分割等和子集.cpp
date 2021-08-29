/*
����һ�� ֻ���������� �� �ǿ� ����?nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
ʾ�� 1��
���룺nums = [1,5,11,5]
�����true
���ͣ�������Էָ�� [1, 5, 5] �� [11] ��
ʾ�� 2��
���룺nums = [1,2,3,5]
�����false
���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ���
��ʾ��
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        for (int i = 0; i < nums.size(); i++)
            for (int j = sum / 2; j >=nums[i] ; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        if (dp[sum / 2] == sum / 2)
            return true;
        return false;
    }
};

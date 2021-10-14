/*
����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
���������������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3,6,2,7] ������ [0,3,1,6,2,2,7] �������С�
ʾ�� 1��
���룺nums = [10,9,2,5,3,7,101,18]
�����4
���ͣ�������������� [2,3,7,101]����˳���Ϊ 4 ��
ʾ�� 2��
���룺nums = [0,1,0,3,2,3]
�����4
ʾ�� 3��
���룺nums = [7,7,7,7,7,7,7]
�����1
��ʾ��
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
���ף�
��������ʱ�临�Ӷ�Ϊ O(n^2) �Ľ��������
���ܽ��㷨��ʱ�临�ӶȽ��͵� O(n log(n)) ��?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        int ret = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

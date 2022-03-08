/*
����һ���� ��ͬ ������ɵ����� nums ����һ��Ŀ������ target ������� nums ���ҳ��������ܺ�Ϊ target ��Ԫ����ϵĸ�����
��Ŀ���ݱ�֤�𰸷��� 32 λ������Χ��
ʾ�� 1��
���룺nums = [1,2,3], target = 4
�����7
���ͣ�
���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
��ע�⣬˳��ͬ�����б�������ͬ����ϡ�
ʾ�� 2��
���룺nums = [9], target = 3
�����0
��ʾ��
1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums �е�����Ԫ�� ������ͬ
1 <= target <= 1000
���ף���������������к��и����ᷢ��ʲô�������������ֱ仯��������������֣���Ҫ����Ŀ�������Щ����������
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[target+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto &e : nums)
            {
                if (e > i)
                    break;
                dp[i] = 0LL + dp[i] + dp[i - e] % INT_MAX;
            }
        }
        return dp[target];
    }
};

/*
�� n �����򣬱��Ϊ0 �� n - 1��ÿ�������϶�����һ�����֣���Щ���ִ������� nums �С�
����Ҫ����������е����򡣴��Ƶ� i ����������Ի��?nums[i - 1] * nums[i] * nums[i + 1] öӲ�ҡ�?����� i - 1 �� i + 1 �����?i?���ڵ������������š���� i - 1�� i + 1 ����������ı߽磬��ô�͵�����һ������Ϊ 1 ������
�����ܻ��Ӳ�ҵ����������
ʾ�� 1��
���룺nums = [3,1,5,8]
�����167
���ͣ�
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
ʾ�� 2��
���룺nums = [1,5]
�����10
��ʾ��
n == nums.length
1 <= n <= 500
0 <= nums[i] <= 100
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int> > dp(nums.size(), vector<int> (nums.size(), 0));
        for (int l = 2; l < nums.size(); l++)
            for (int i = 0; i < nums.size() - l; i++)
                for (int k = i + 1; k < i + l; k++)
                    dp[i][i + l] = max(dp[i][i + l], dp[i][k] + dp[k][i + l] + nums[i] * nums[k] * nums[i + l]);
        return dp.front().back();
    }
};

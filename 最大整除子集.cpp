/*
����һ���� ���ظ� ��������ɵļ��� nums �������ҳ��������������������Ӽ� answer ���Ӽ���ÿһԪ�ض� (answer[i], answer[j]) ��Ӧ�����㣺
answer[i] % answer[j] == 0 ����
answer[j] % answer[i] == 0
������ڶ����Ч���Ӽ������������κ�һ�����ɡ�
ʾ�� 1��
���룺nums = [1,2,3]
�����[1,2]
���ͣ�[1,3] Ҳ�ᱻ��Ϊ��ȷ�𰸡�
ʾ�� 2��
���룺nums = [1,2,4,8]
�����[1,2,4,8]
��ʾ��
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
nums �е��������� ������ͬ
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        pair<int, int> dp[n];  // <nums[i] Ϊ��β�����������Ӽ��Ĵ�С, �����������������±�>
        for(int i = 0; i < n; i++)
        {
            pair<int, int> p = {1, i};
            for (int j = 0; j < i; j++)
            	if (nums[i] % nums[j] == 0 && dp[j].first + 1 > p.first)
                    p = {dp[j].first + 1, j};
            dp[i] = p;
        }

        int idx = max_element(dp, dp + n) - dp;  // dp.first �����Ǹ��±� 
        int val = dp[idx].first;
        vector<int> v;
        while (val--)
        {
        	v.push_back(nums[idx]);
        	idx = dp[idx].second;
        }
        return v;
    }
};

// dp[i] ��ʾ��nums[i]Ϊ��β�����������Ӽ��Ĵ�С ������nums������
// ת�Ʒ��� ����LIS��������������У�
// ����nums[i]����Ҫ���[0, i-1]λ�ϵ�nums[j]��ʹ��nums[i] % nums[j] == 0����nums[j]��nums[i]��һ��������
// �õ� 
// dp[i] = max{j��[0,i-1]} (dp[j]+1), if nums[i]%nums[j] == 0
// ʱ�临�Ӷȣ�O(nlogn+n^2)=O(n^2) ����+��λ�����ǰ�������Ԫ��
// �ռ临�Ӷȣ�O(n)


/*
���һ���㷨���ҳ�����������֮��Ϊָ��ֵ�����������ԡ�һ����ֻ������һ�����ԡ�
ʾ�� 1:
����: nums = [5,6,5], target = 11
���: [[5,6]]
ʾ�� 2:
����: nums = [5,6,5,6], target = 11
���: [[5,6],[5,6]]
��ʾ��
nums.length <= 100000
*/

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        for (auto n : nums)
            if (--mp[n] >= 0 && --mp[target - n] >= 0)
                ans.push_back({n, target - n});
        return ans;
    }
};

/*
����һ����СΪ n ���������飬�ҳ��������г��ֳ��� n/3 �ε�Ԫ�ء�
ʾ�� 1��
���룺[3,2,3]
�����[3]
ʾ�� 2��
���룺nums = [1]
�����[1]
ʾ�� 3��
���룺[1,1,1,3,3,2,2,2]
�����[1,2]
��ʾ��
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> m;
        for (int num : nums)
            m[num]++;

        vector<int> v;
        for (auto &[key, val] : m)
            if (val > n)
                v.push_back(key);
        return v;
    }
};

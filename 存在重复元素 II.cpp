/*
����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums [i] = nums [j]������ i �� j �Ĳ�� ����ֵ ����Ϊ k��
ʾ�� 1:
����: nums = [1,2,3,1], k = 3
���: true
ʾ�� 2:
����: nums = [1,0,1,1], k = 1
���: true
ʾ�� 3:
����: nums = [1,2,3,1,2,3], k = 2
���: false
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cur = nums[i];
            if (s.find(cur) == s.end())
            {
                s.insert(cur);
                if (s.size() > k)
                    s.erase(nums[i - k]);
            }
            else
                return true;
        }
        return false;
    }
};

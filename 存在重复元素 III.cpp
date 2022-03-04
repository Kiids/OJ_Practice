/*
����һ���������� nums ���������� k �� t �������ж��Ƿ���� ������ͬ�±� i �� j��ʹ�� abs(nums[i] - nums[j]) <= t ��ͬʱ������ abs(i - j) <= k ��
��������򷵻� true�������ڷ��� false��
ʾ�� 1��
���룺nums = [1,2,3,1], k = 3, t = 0
�����true
ʾ�� 2��
���룺nums = [1,0,1,1], k = 1, t = 2
�����true
ʾ�� 3��
���룺nums = [1,5,9,1,5,9], k = 2, t = 3
�����false
��ʾ��
0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (right - left > k)
            {
                s.erase(nums[left]);
                left++;
            }
            auto a = s.lower_bound((long long) nums[right] - t);
            if (a != s.end() && abs(*a - nums[right]) <= t)
                return true;
            s.insert(nums[right]);
        }
        return false;
    }
};

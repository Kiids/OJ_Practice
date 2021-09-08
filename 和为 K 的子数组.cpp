/*
����һ���������� nums ��һ������ k ������ͳ�Ʋ����ظ������к�Ϊ k ������������ĸ�����
ʾ�� 1��
���룺nums = [1,1,1], k = 2
�����2
ʾ�� 2��
���룺nums = [1,2,3], k = 3
�����2
��ʾ��
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int ret = 0, pre = 0;
        for (int y : nums)
        {
            pre += y;
            int x = pre - k;
            ret += m[x];
            m[pre] ++;
        }
        return ret;
    }
};

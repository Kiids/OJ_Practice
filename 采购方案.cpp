/*
С���� N ������ı��۴������� nums��С��Ԥ��Ϊ target���ٶ�С�����������������Ҫ��������Ļ��Ѳ�����Ԥ�㣬�������ж����ֲɹ�������
ע�⣺����Ҫ�� 1e9 + 7 (1000000007) Ϊ��ȡģ���磺�����ʼ���Ϊ��1000000008���뷵�� 1
ʾ�� 1��
���룺nums = [2,5,3,5], target = 6
�����1
���ͣ�Ԥ���ڽ��ܹ��� nums[0] �� nums[2]��
ʾ�� 2��
���룺nums = [2,2,1,9], target = 10
�����4
���ͣ�����Ԥ��Ĳɹ��������£�
nums[0] + nums[1] = 4
nums[0] + nums[2] = 3
nums[1] + nums[2] = 3
nums[2] + nums[3] = 10
��ʾ��
2 <= nums.length <= 10^5
1 <= nums[i], target <= 10^5
*/

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        long long ret = 0, mod = 1000000007;
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for (i = 0; i < j; i++)
        {
            while (j > i && nums[i] + nums[j] > target)
                j--;
            ret += j - i;
        }
        return ret % mod;
    }
};

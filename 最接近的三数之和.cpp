/*
����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
ʾ����
���룺nums = [-1,2,1,-4], target = 1
�����2
���ͣ��� target ��ӽ��ĺ��� 2 (-1 + 2 + 1 = 2) ��
��ʾ��
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int temp = abs(nums[0] + nums[1] + nums[2] - target), ret = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (temp > abs(nums[i] + nums[left] + nums[right] - target))
                {
                    temp = abs(nums[i] + nums[left] + nums[right] - target);
                    ret = nums[i] + nums[left] + nums[right];
                }
                if (nums[i] + nums[left] + nums[right] > target)
                {
                    right--;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] < target)
                {
                    left++;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] == target)
                    return nums[i] + nums[left] + nums[right];
            }
        }
        return ret;
    }
};

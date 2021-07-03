/*
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。
你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
示例：
输入:
[4,3,2,7,8,2,3,1]
输出:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v(nums.size()), ret;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i + 1)
                i++;
            else
            {
                int t = nums[i];
                if (nums[t - 1] == t)
                {
                    v[t - 1]++;
                    i++;
                }
                else
                    swap(nums[t - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (v[i])
                ret.push_back(i + 1);
        return ret;
    }
};

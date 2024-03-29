/*
给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
示例 1:
输入: [2,2,3,4]
输出: 3
解释:
有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:
数组长度不超过1000。
数组里整数的范围为 [0, 1000]。
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int x = nums.size() - 1; x >= 2; x--) 
        {
            int i = 0, j = x - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[x])
                {
                    ret += j - i;
                    j--;
                }
                else
                    i++;
            }
        }
        return ret;
    }
};

/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
提示：
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        while(true)
        {
        	v.push_back(nums);
        	fun(nums);
            if (nums == v[0])
            	break;
        }
        return v;	
    }

    void fun(vector<int>& nums)
    {
		int i = nums.size() - 2, k;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
		for(k = i + 1; k <= (nums.size() + i) / 2; k++)
        	swap(nums[k], nums[nums.size() - (k - i)]);
        k = i + 1;
        while(i >= 0 && k < nums.size() && nums[k] <= nums[i])
            k++;
		if(i >= 0 && k < nums.size())
			swap(nums[i], nums[k]);
    }
};

//每次按字典顺序构造当前解的下一个排列，当下一个排列与第一个相等时退出。
//时间：O(n*n!);
//空间：O(n!);


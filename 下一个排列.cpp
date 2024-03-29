/*
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。
示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]
提示：
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur = nums.size() - 2;
        while (cur >= 0 && nums[cur] >= nums[cur + 1])
            cur--;

        if (cur < 0)
            sort(nums.begin(), nums.end());
        else
        {
            int pos = nums.size() - 1;
            while (nums[pos] <= nums[cur])
                pos--;

            swap(nums[cur], nums[pos]);
            reverse(nums.begin() + cur + 1, nums.end());
        }
    }
};

//从后往前寻找到第一个降序的位置（全部升序说明数组已经是最大值）
//找到上面标记的下一个位置
//交换这两个位置
//交换之后从此位置之后是降序的
//将这部分进行反转，得到升序序列（最小值） 

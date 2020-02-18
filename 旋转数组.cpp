/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*int t = 0, len = nums.size();
        int l = k % len;
        for (int i = 0; i < l; i++)
        {
            t = nums[len - 1];
            for (int j = len - 2; j >= 0; j--)
                nums[j + 1] = nums[j];
            nums[0] = t;
        }  超出时间限制
        */
        //确定移动次数
        k %= nums.size();
        //将整个数组逆序
        reserve(nums, 0, nums.size() - 1);
        //将前k个逆序
        reserve(nums, 0, k-1);
        //从下标k到数组长度之间逆序
        reserve(nums, k, nums.size() - 1);
    }
    void reserve(vector<int>& arr, int start, int end) 
	{
        while(start < end) 
		{
            int tmp = arr[end];
            arr[end--] = arr[start];
            arr[start++] = tmp;
        }
    }
};

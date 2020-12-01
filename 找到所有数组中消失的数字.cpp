/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
示例:
输入:
[4,3,2,7,8,2,3,1]
输出:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return nums;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = (nums[i] - 1) % nums.size();
            nums[index] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= nums.size())
                ret.push_back(i + 1);
        }
        return ret;
    }
};
//将数组元素对应为索引的位置加n
//遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在，即消失的数字

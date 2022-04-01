/*
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
示例 1：
输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
示例 2：
输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
示例 3：
输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
提示：
1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto num : nums)
        {
            if (num <= small)
            	small = num;
            else if (num <= mid)
                mid = num;
            else if (num > mid)
            	return true;
        }
        return false;    
    }
};

//新建两个变量 small 和 mid ，用来保存长度为 3 的递增子序列的最小值和中间值。
//遍历数组，每遇到一个数字，将它和 small 和 mid 相比，若小于等于 small ，则替换 small；
//否则，若小于等于 mid，则替换 mid；否则，若大于 mid，则说明找到了长度为 3 的递增数组
//
//当已经找到了长度为 2 的递增序列，这时又来了一个比 small 还小的数字，为什么可以直接替换 small ，
//这样 small 和 mid 在原数组中并不是按照索引递增的关系
//假如当前的 small 和 mid 为 [3, 5]，这时又来了个 1。假如我们不将 small 替换为 1，
//那么，当下一个数字是 2，后面再接上一个 3 的时候，我们就没有办法发现这个 [1,2,3] 的递增数组了
//也就是说，替换最小值，是为了后续能够更好地更新中间值！
//即使更新了 small ，这个 small 在 mid 后面，没有严格遵守递增顺序，但它隐含着的真相是，
//有一个比 small 大比 mid 小的前最小值出现在 mid 之前。因此，当后续出现比 mid 大的值的时候，
//一样可以通过当前 small 和 mid 推断的确存在着长度为 3 的递增序列


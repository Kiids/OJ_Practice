/*
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
如果存在则返回 true，不存在返回 false。
示例 1：
输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
示例 2：
输入：nums = [1,0,1,1], k = 1, t = 2
输出：true
示例 3：
输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false
提示：
0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (right - left > k)
            {
                s.erase(nums[left]);
                left++;
            }
            auto a = s.lower_bound((long long) nums[right] - t);
            if (a != s.end() && abs(*a - nums[right]) <= t)
                return true;
            s.insert(nums[right]);
        }
        return false;
    }
};

//在从小到大的排序数组中，
//lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，
//找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
//upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，
//找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。


//right 指针每次后移，如果发现 set 的大小大于 k ，则需要把 nums[left] 从 set 中删除；
//查找 set 中是否有大于等于 nums[right] - t 的元素，如果有的话，
//说明在大小不超过为 k 的窗口内有绝对值差小于等于 t 的两个元素，返回 true。
//如果把 nums 遍历了一遍仍然没有结果，则返回 false。



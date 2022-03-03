/*
给定一个大小为 n 的整数数组，找出其中所有出现超过 n/3 次的元素。
示例 1：
输入：[3,2,3]
输出：[3]
示例 2：
输入：nums = [1]
输出：[1]
示例 3：
输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
提示：
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> m;
        for (int num : nums)
            m[num]++;

        vector<int> v;
        for (auto &[key, val] : m)
            if (val > n)
                v.push_back(key);
        return v;
    }
};

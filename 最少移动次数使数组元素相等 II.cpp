/*
给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。
例如:
输入:
[1,2,3]
输出:
2
说明：
只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）： 
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ret = 0, i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j)
            ret += nums[j--] - nums[i++];
        return ret;
    }
};

// 双指针 
// 转化为求数轴上n个点到某个点距离和的最小值，即找到这个使距离和最小的点—中位数 
// 计算从两边到中间，逐个加上区间长度，直到没东西可加为止。

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int mid = nums[N / 2], ret = 0;
        for (int n : nums)
            ret += abs(n - mid);
        return ret;
    }
};

// 排序
// 取中位数
// 计算将所有数字移动到中位数需要移动多少次，并累加


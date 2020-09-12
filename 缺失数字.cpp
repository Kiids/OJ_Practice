/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if(i != nums[i])
                return i;
        return nums.size();
    }
};

// 异或
// nums.size()的大小即为n,将0到n异或,并且同时异或nums[0]到nums[n-1],共2n+1个数,
// 相同的数异或结果为0, 0 ^ a = a,所以最后的结果是缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    int ret = nums.size();
	    for (int i = 0; i < nums.size(); i++)
	        ret = ret ^ i ^ nums[i];            // a^b^b = a;
	    return ret ;
    }
};

// 数学求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    int sum = 0, n = nums.size();
	    for (int n : nums)   
	        sum += n;
	    return (n * (n + 1)) / 2 - sum;
    }
};

// 二分
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    sort(nums.begin(), nums.end());
	    int left = 0, right = nums.size(), mid = (left + right) / 2;
	    while (left < right)
	    {
	        mid = (left + right) / 2;
	        if (nums[mid] > mid)
				right = mid;
	        else
				left = mid + 1;
	    }
	    return left;
    }
};

// 排序（不符合线性条件）
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if(i != nums[i])
                return i;
        return nums.size();
    }
};

// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
// 示例 1:
// 输入: [2,2,3,2]
// 输出: 3
// 示例 2:
// 输入: [0,1,0,1,0,1,99]
// 输出: 99

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = 0;
            for (int j = 0; j < n; j++)
                bit += (nums[j]>>i) & 1;
            
            ret |= (bit%3) << i;
        }
        return ret;
    }
};

// int 整型共有32位，用bitnum[32]存储这n个数据每个二进制位上1出现的个数，再%3，如果为1，那说明这一位是要找元素二进制表示中为1 的那一位


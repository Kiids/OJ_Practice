/*
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
示例 1：
输入：n = 3, k = 3
输出："213"
示例 2：
输入：n = 4, k = 9
输出："2314"
示例 3：
输入：n = 3, k = 1
输出："123"
提示：
1 <= n <= 9
1 <= k <= n!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        v[0] = 1;
        for (int i = 1; i < n; i++)               // 记录 i!，以 i 开头的全排列个数 
            v[i] = i * v[i - 1];
            
        k--;                                     // 索引从 0 开始
        string s;
        vector<int> nums;
        for (int i = 1; i <= n; i++)             // 记录 i 
            nums.push_back(i);
        for (int i = 1; i <= n; i++)
        {
            int order = k / v[n - i];            // 获取第一个数字 
            s.push_back(nums[order] + '0');      // 加入第一个数字 
            for (int j = order; j < n - i; j++)  // 从 nums 中删除加入的这个数字 
                nums[j] = nums[j + 1];
            k %= v[n - i];                       // 下一轮的第几个 
        }
        return s;
    }
};

// 例： n = 6, k = 373
// 初始化数组 nums = [1, 2, 3, 4, 5, 6]
// 首先，以 1 开头的全排列有 5! 个，以 2 开头的全排列有 5! 个 …… 共 5! * 6 = 6! 个；
// 1、故 k = 373 时，全排列的第一个数字应该是 nums[k / 5!] = 4;
// 2、数组删除 4, 此时 nums = [1, 2, 3, 5, 6]; k = k % 5! = 12;
// 3、接下来就是在 nums 中找第 12 个全排列，重复 1，2 步即可 。
// 注意数组下标是从 0 开始，k 首先要减去 1


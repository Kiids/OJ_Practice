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
        for(int i = 1; i < n; i++)
            v[i] = i * v[i - 1];
            
        k--;
        string s;
        vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        for (int i = 1; i <= n; i++)
        {
            int order = k / v[n - i];
            s.push_back(nums[order] + '0');
            for (int j = order; j < n - i; j++)
                nums[j] = nums[j + 1];
            k %= v[n - i];
        }
        return s;
    }
};

/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
提示：
1 <= k <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& x: nums)
        {
            if (q.size() < k)
                q.emplace(x);
            else
                if (x > q.top())
                {
                    q.pop();
                    q.emplace(x);
                }
        }
        return q.top();
    }
};


class Solution {
    int partition(vector<int>& v, int l, int r)
    {
        int x = v[l], t = l;
        while (l < r)
        {
            while (l < r && v[r] <= x)
                r--;
            while (l < r && v[l] >= x)
                l++;
            if (l < r)
                swap(v[l], v[r]);
        }
        swap(v[t], v[l]);
        return l;
    }

    int fun(int k, vector<int>& v, int l, int r)
    {
        while (true)
        {
            int idx = partition(v, l, r);
            if (idx == k - 1)
                return v[idx];
            else if (idx < k - 1)
                l = idx + 1;
            else    
                r = idx - 1;
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return fun(k, nums, 0, nums.size() - 1);
    }
};
// 快速排序  时间复杂度 O(n)

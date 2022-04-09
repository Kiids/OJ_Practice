/*
给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
示例 1:
输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:
输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:
输入: nums1 = [1,2], nums2 = [3], k = 3 
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
提示:
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 和 nums2 均为升序排列
1 <= k <= 1000
*/

class Solution {
    bool flag = true;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        int n = nums1.size(), m = nums2.size();
        if (n > m)  // 确保nums1为两数组中长度较少的那个
        {
            swap(nums1, nums2);
            swap(m,n);
            flag = false;
        }
        auto cmp = [&](const auto& a, const auto& b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(cmp) > q(cmp);
        for (int i = 0; i < min(n, k); i++)
            q.push( {i, 0} );
        while (v.size() < k and q.size())
        {
            auto [a,b] = q.top();
            q.pop();
            flag ? v.push_back( {nums1[a], nums2[b]}) : v.push_back( {nums2[b], nums1[a]});
            if(b + 1 < m) q.push( {a, b + 1} );
        }
        return v;
    }
};

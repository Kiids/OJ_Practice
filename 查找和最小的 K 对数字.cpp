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
            swap(m, n);
            flag = false;
        }
        auto cmp = [&](const auto& a, const auto& b){  // 定义比较规则
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(n, k); i++)
            q.push( {i, 0} );
        while (v.size() < k and q.size())
        {
            auto [a,b] = q.top();
            q.pop();
            flag ? v.push_back( {nums1[a], nums2[b]}) : v.push_back( {nums2[b], nums1[a]});
            if (b + 1 < m)
				q.push( {a, b + 1} );
        }
        return v;
    }
};

// 起始将这 n 个序列的首位元素（点对）以二元组 (i,j) 放入优先队列（小根堆），
// 其中 i 为该点对中 nums1[i] 的下标，j 为该点对中 nums2[j] 的下标，
// 始终确保 nums1 为两数组中长度较少的那个，然后通过标识位来记录是否发生过交换，
// 确保答案的点顺序的正确性。每次从优先队列（堆）中取出堆顶元素
// 含义为当前未被加入到答案的所有点对中的最小值，加入答案，
// 并将该点对所在序列的下一位（如果有）加入优先队列中。
// template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> >
// class priority_queue;
// class T：T是优先队列中存储的元素的类型。
// class Container = vector<T>：Container是优先队列底层使用的存储结构，默认vector。
// class Compare = less<typename Container::value_type> ：Compar是定义优先队列中元素的比较方式的类。
// decltype操作符，用于查询表达式的数据类型。decltype在C++11标准制定时引入，主要是为泛型编程而设计，
// 以解决泛型编程中，由于有些类型由模板参数决定，而难以（甚至不可能）表示之的问题。
// decltype选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。

class Solution {
    bool flag = true;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        auto cmp = [&nums1, &nums2] (const pair<int, int>& p, const pair<int, int>& q) {
            return nums1[p.first] + nums2[p.second] > nums1[q.first] + nums2[q.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);  // 优先级队列，保存 [index1, index2]
        for (int i = 0; i < nums1.size(); i++)  // 把 nums1 的所有索引入队，nums2 的索引初始时都是 0
            pq.push(make_pair(i, 0));
        while(!pq.empty() && v.size() < k)      // 最多弹出 k 次
        {
            auto p = pq.top();
            pq.pop();
            v.push_back({nums1[p.first], nums2[p.second]});
            if (p.second < nums2.size() - 1)    // 将 index2 加 1 之后继续入队
                pq.push(make_pair(p.first, p.second + 1));
        }
        return v;
    }
};

// 假设第一个数组长度为m，第二个长度为n；实际上就是要把所有数对分成m份，
// 每份都是第一个数组中某个数和第二个数组中每一个数组合而成，由于第二个数组是单调增的，
// 所以这m个数对也各自是单调增的。问题就转化为了从m个数对序列中，取出最小的k个数对，多路归并问题。
// 用一个堆将每一路最小的元素加入堆中；对堆中元素逐个出堆，每出一个就将该序列中的下一个元素加入队伍中。


/*
给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。
请你返回 任意 一个长度为 k 的整数子序列。
子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。
示例 1：
输入：nums = [2,1,3,3], k = 2
输出：[3,3]
解释：
子序列有最大和：3 + 3 = 6 。
示例 2：
输入：nums = [-1,-2,3,4], k = 3
输出：[-1,3,4]
解释：
子序列有最大和：-1 + 3 + 4 = 6 。
示例 3：
输入：nums = [3,4,3,3], k = 2
输出：[3,4]
解释：
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
提示：
1 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qId;
        priority_queue<pair<int, int>> qValue;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
            qValue.push({nums[i], i});
        for (int i = 0; i < k; i++)
        {
            qId.push({qValue.top().second, qValue.top().first});
            qValue.pop();
        }
        for (int i = 0; i < k; i++)
        {
            v.push_back(qId.top().second);
            qId.pop();
        }
        return v;
    }
};

//std::priority_queue:优先队列，类似堆(heap)
//priority_queue<Type, Container, Functional>, Type数据类型，Container保存数据的容器，Functional元素比较方式。
//Container必须是用数组实现的容器，比如 vector, deque. STL里面默认用的是vector. 比较方式默认用operator< , 
//如果把后面两个参数缺省的话，优先队列就是大顶堆，队头元素最大。


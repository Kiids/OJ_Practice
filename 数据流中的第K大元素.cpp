/*
设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。
示例:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明:
你可以假设 nums 的长度≥ k-1 且k ≥ 1。
*/

// 利用set自动排序
class KthLargest {
    int K;
    multiset<int> m;
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto e : nums)
        {
            m.insert(e);
            if (m.size() > k)
                m.erase(m.begin());
        }
        K = k;
    }
    
    int add(int val) {
        m.insert(val);
        if (m.size() > K)
            m.erase(m.begin())
        return *m.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
// 堆
// priority_queue<Type, Container, Functional>
// Type为数据类型， Container为保存数据的容器，Functional为元素比较方式
// 如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大
// 本题为小顶堆

class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};

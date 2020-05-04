/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：
输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：
输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
限制：
最多会对 addNum、findMedia进行 50000 次调用。
*/

//时间复杂度：O(logn)。堆插入和删除需要 O(logn)，查找中位数需要 O(1)。
//空间复杂度：O(n)。
class MedianFinder {
    priority_queue<int> l;  // 大顶堆，存放中位数左边较小的一半数字
    priority_queue<int, vector<int>, greater<int>> h;  // 小顶堆，存放中位数右边较大的一半数字
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        l.push(num);  // 入堆 
        h.push(l.top());  // 平衡 
        l.pop();
        if (l.size() < h.size())  // 调整两个堆元素个数 
        {
            l.push(h.top());
            h.pop();
        }
    }
    
    double findMedian() {
        return l.size() > h.size() ? (double)l.top() : (l.top() + h.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


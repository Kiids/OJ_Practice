/*
假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。请实现数据结构和算法来支持这些操作，也就是说：
实现 track(int x) 方法，每读入一个数字都会调用该方法；
实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。
注意：本题相对原题稍作改动
示例:
输入:
["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
[[], [1], [0], [0]]
输出:
[null,0,null,1]
提示：
x <= 50000
track 和 getRankOfNumber 方法的调用次数均不超过 2000 次
*/

class StreamRank {
private:
    vector<int> nums;
public:
    StreamRank() {
        
    }
    
    void track(int x) {
        stack<int> tmp;
        while (nums.size() && nums.back() > x)
            tmp.push(nums.back()), nums.pop_back();
        nums.push_back(x);
        while (tmp.size()) nums.push_back(tmp.top()), tmp.pop(); 
    }
    
    int getRankOfNumber(int x) {
        if (nums.empty() || nums[0] > x)
            return 0;
        if (nums.back() <= x)
            return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return r + 1;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */

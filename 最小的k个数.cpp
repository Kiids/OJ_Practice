/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/

// 堆 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret;
        if (k == 0)
            return ret;

        priority_queue<int> q;
        for (auto a : arr)
        {
            if (q.size() < k)
                q.push(a);
            else
            {
                if (q.top() > a)
                {
                    q.pop();
                    q.push(a);
                }
            }
        }

        while (!q.empty())
        {
            ret.push_back(q.top());
            q.pop();
        }

        return ret;
    }
};

// 快排思想
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == k) return arr;
        if (n < k || k <= 0 || n == 0) return vector<int>();
        int l = 0, r = n - 1;
        int index = partition(arr, l, r);
        while (index != k - 1) {
            if (index > k-1) r = index - 1;
            else l = index + 1;
            index = partition(arr, l, r);
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    int partition(vector<int>& arr, int l, int r) {
        int temp = arr[l];
        while (l < r) {
            while (l < r && arr[r] >= temp) r--;
            arr[l] = arr[r];
            while (l < r && arr[l] <= temp) l++;
            arr[r] = arr[l]; 
        }
        arr[l] = temp;
        return l;
    }
};
// BFPRT算法
// https://zhuanlan.zhihu.com/p/31498036

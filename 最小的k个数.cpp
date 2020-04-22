/*
������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
ʾ�� 1��
���룺arr = [3,2,1], k = 2
�����[1,2] ���� [2,1]
ʾ�� 2��
���룺arr = [0,1,2,1], k = 1
�����[0]
���ƣ�
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/

// �� 
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

// ����˼��
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
// BFPRT�㷨
// https://zhuanlan.zhihu.com/p/31498036

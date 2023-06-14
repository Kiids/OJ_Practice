/*
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
ʾ�� 1:
����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ�� 2:
����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
��ʾ��
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
// ��������  ʱ�临�Ӷ� O(n)

/*
���һ���㷨���ҳ���������С��k������������˳�򷵻���k�������ɡ�
ʾ����
���룺 arr = [1,3,5,7,2,4,6,8], k = 4
����� [1,2,3,4]
��ʾ��
0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))
*/

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> q;
        for (int a : arr)
        {
            q.push(a);
            if (q.size() > k)
                q.pop();
        }
        while (!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

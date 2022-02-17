/*
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
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

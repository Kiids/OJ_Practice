/*
����һ���������� nums ��һ������ k ������Ҫ�ҵ� nums �г���Ϊ k �� ������ ������������е� ����� ��
���㷵�� ���� һ������Ϊ k �����������С�
������ ����Ϊ��һ��������ɾ��һЩԪ�غ󣬲��ı�ʣ��Ԫ�ص�˳��õ������顣
ʾ�� 1��
���룺nums = [2,1,3,3], k = 2
�����[3,3]
���ͣ�
�����������ͣ�3 + 3 = 6 ��
ʾ�� 2��
���룺nums = [-1,-2,3,4], k = 3
�����[-1,3,4]
���ͣ�
�����������ͣ�-1 + 3 + 4 = 6 ��
ʾ�� 3��
���룺nums = [3,4,3,3], k = 2
�����[3,4]
���ͣ�
�����������ͣ�3 + 4 = 7 ��
��һ�����е�������Ϊ [4, 3] ��
��ʾ��
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

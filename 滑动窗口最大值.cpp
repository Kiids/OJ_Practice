/*
����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
���� ���������е����ֵ ��
ʾ�� 1��
���룺nums = [1,3,-1,-3,5,3,6,7], k = 3
�����[3,3,5,5,6,7]
���ͣ�
�������ڵ�λ��                ���ֵ
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
ʾ�� 2��
���룺nums = [1], k = 1
�����[1]
��ʾ��
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0)
            return {};
		vector<int> v;
		deque<size_t> window;  // ˫����б��浱ǰ�������ֵ������λ�� ����������λ�õ���ֵ�Ӵ�С����
		for (size_t i = 0; i < k; i++)
        {
			while (!window.empty() && nums[i] > nums[window.back()])  // �Ӵ�С ���ǰ����С����Ҫ������ֱ������Ҫ��
				window.pop_back();
			window.push_back(i);  // ��ӵ�ǰֵ��Ӧ�������±�
		}
		v.push_back(nums[window.front()]);
		for (size_t i = k; i < nums.size(); i++)
        {
			if (!window.empty() && window.front() <= i - k)  // �жϵ�ǰ�����ж��׵�ֵ�Ƿ���Ч
				window.pop_front();
			while (!window.empty() && nums[i] > nums[window.back()])
				window.pop_back();
			window.push_back(i);
			v.push_back(nums[window.front()]);  // ���ڳ��� k  ���浱ǰ���������ֵ
		}
		return v;
    }
};

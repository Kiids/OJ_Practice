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
		deque<size_t> window;
		for (size_t i = 0; i < k; i++)
        {
			while (!window.empty()  && nums[i] > nums[window.back()])
				window.pop_back();
			window.push_back(i);
		}
		v.push_back(nums[window.front()]);
		for (size_t i = k; i < nums.size(); i++)
        {
			if (!window.empty() && window.front() <= i - k)
				window.pop_front();
			while (!window.empty() && nums[i] > nums[window.back()])
				window.pop_back();
			window.push_back(i);
			v.push_back(nums[window.front()]);
		}
		return v;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums == null || nums.length < 2)
            return nums;
        // ˫����� ���浱ǰ�������ֵ������λ�� ��֤����������λ�õ���ֵ���Ӵ�С����
        LinkedList<Integer> queue = new LinkedList();
        // �������
        int[] result = new int[nums.length-k+1];
        // ����nums����
        for (int i = 0; i < nums.length; i++)
        {
            // ��֤�Ӵ�С ���ǰ����С����Ҫ���ε�����ֱ������Ҫ��
            while (!queue.isEmpty() && nums[queue.peekLast()] <= nums[i])
                queue.pollLast();
            // ��ӵ�ǰֵ��Ӧ�������±�
            queue.addLast(i);
            // �жϵ�ǰ�����ж��׵�ֵ�Ƿ���Ч
            if (queue.peek() <= i - k)
                queue.poll();
            // �����ڳ���Ϊkʱ ���浱ǰ���������ֵ
            if (i + 1 >= k)
                result[i + 1 - k] = nums[queue.peek()];
        }
        return result;
    }
};

/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：
输入：nums = [1], k = 1
输出：[1]
提示：
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
        // 双向队列 保存当前窗口最大值的数组位置 保证队列中数组位置的数值按从大到小排序
        LinkedList<Integer> queue = new LinkedList();
        // 结果数组
        int[] result = new int[nums.length-k+1];
        // 遍历nums数组
        for (int i = 0; i < nums.length; i++)
        {
            // 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
            while (!queue.isEmpty() && nums[queue.peekLast()] <= nums[i])
                queue.pollLast();
            // 添加当前值对应的数组下标
            queue.addLast(i);
            // 判断当前队列中队首的值是否有效
            if (queue.peek() <= i - k)
                queue.poll();
            // 当窗口长度为k时 保存当前窗口中最大值
            if (i + 1 >= k)
                result[i + 1 - k] = nums[queue.peek()];
        }
        return result;
    }
};

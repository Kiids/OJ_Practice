/*
魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
示例1:
 输入：nums = [0, 2, 3, 4, 5]
 输出：0
 说明: 0下标的元素为0
示例2:
 输入：nums = [1, 1, 1]
 输出：1
提示:
nums长度在[1, 1000000]之间
*/

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == i)
                return i;
        return -1;
    }
};

// 二分法
class Solution {
private:
    void binary_search(vector<int>& nums, int left, int right, int& ret){
        // 剪枝
        if (ret != -1 && ret < left)
			return;
        if (left <= right)
		{
            int mid = left + (right - left) / 2;
            // 如果找到目标的索引，需要尝试能否找到更小的索引值
            if (nums[mid] == mid)
			{
                if (ret == -1)
					ret = mid;
                else if (mid < ret)
					ret = mid;
                binary_search(nums, left, mid - 1, ret);
            }
            // 如果mid不符合要求，则需要在mid两边继续查找
			else
			{
                binary_search(nums, left, mid - 1, ret);
                binary_search(nums, mid + 1, right, ret);
            }
        }
    }
public:
    int findMagicIndex(vector<int>& nums) {
        int ret = -1;
        binary_search(nums, 0, nums.size()-1, ret);
        return ret;
    }
};

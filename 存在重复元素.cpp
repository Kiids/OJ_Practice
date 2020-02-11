/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
示例 1:
输入: [1,2,3,1]
输出: true
示例 2:
输入: [1,2,3,4]
输出: false
示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*for (size_t i = 0; i < nums.size() - 1; i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return true;
        }
        return false;  会超出时间限制*/
        /*std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
        执行出错 Line 923: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)*/
        unordered_map<int, int>count;
		for (auto &e : nums)
			count[e]++;
		/*for (auto &e : count) {
			if (e.second > 1) {
				return 1;
			}
		}
		return 0;*/
		return count.size() != nums.size();
    }
};

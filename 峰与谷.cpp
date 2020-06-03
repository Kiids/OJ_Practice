/*
在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 6, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。
示例:
输入: [5, 3, 1, 2, 3]
输出: [5, 1, 3, 2, 3]
提示：
nums.length <= 10000
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end(), greater<int>());
        int peek = 0, valley = nums.size() / 2;
        if (nums.size() & 0x1)
            valley++;
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (peek < valley)
                nums[i] = v[peek++];
        }
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (valley < nums.size())
                nums[i] = v[valley++];
        }
    }
};

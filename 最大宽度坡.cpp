/*
给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
找出 A 中的坡的最大宽度，如果不存在，返回 0 。
示例 1：
输入：[6,0,8,2,1,5]
输出：4
解释：
最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
示例 2：
输入：[9,8,1,0,1,9,4,0,4,1]
输出：7
解释：
最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
提示：
2 <= A.length <= 50000
0 <= A[i] <= 50000
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int ret = 0;
        s.push(0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i);  // 单调递减栈 
        }
        for (int j = nums.size() - 1; j >= ret; j--)
        {
            while (s.size() && nums[s.top()] <= nums[j])
            {
                int x = s.top();
                s.pop();
                ret = max(ret, j - x);
            }
        }
        return ret;
    }
};

//先生成一个严格单调递减的数列存进栈中（从位置0开始），这是所有可能的i值；
//从最右边开始找j值，栈顶位置元素值小于等于当前j位置的值，考虑把i的位置向左移动使得长度增加
//（右边界固定寻找最远的左边界），之后再开始减少右边界，如此循环直到j不再满足条件


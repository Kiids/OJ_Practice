/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
限制：
1 <= target <= 10^5

*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 滑动窗口
        int i = 1, j = 1, sum = 0;
        vector<vector<int>> ret;

        while (i <= target / 2)
        {
            if (sum < target)  // 右边界向右移动
            {
                sum += j;
                j++;
            }
            else if (sum > target)  // 左边界向右移动
            {
                sum -= i;
                i++;
            }
            else
            {
                vector<int> v;
                for (int k = i; k < j; k++)
                    v.push_back(k);
                ret.push_back(v);

                // 左边界向右移动
                sum -= i;
                i++;
            }
        }
        return ret;
    }
};


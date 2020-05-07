/*
如果数组中多一半的数都是同一个，则称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。
示例 1：
输入：[1,2,5,9,5,9,5,5,5]
输出：5
示例 2：
输入：[3,2]
输出：-1
示例 3：
输入：[2,2,1,1,1,2,2]
输出：2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0, ret;
        for (int e : nums)
        {
            if (n == 0)
            {
                ret = e;
                n++;
            }
            else
            {
                if (ret == e)
                    n++;
                else
                    n--;
            }
        }
        return ret;
    }
};

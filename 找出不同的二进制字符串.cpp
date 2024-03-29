/*
给你一个字符串数组 nums ，该数组由 n 个 互不相同 的二进制字符串组成，且每个字符串长度都是 n 。请你找出并返回一个长度为?n?且?没有出现 在 nums 中的二进制字符串。如果存在多种答案，只需返回 任意一个 即可。
示例 1：
输入：nums = ["01","10"]
输出："11"
解释："11" 没有出现在 nums 中。"00" 也是正确答案。
示例 2：
输入：nums = ["00","01"]
输出："11"
解释："11" 没有出现在 nums 中。"10" 也是正确答案。
示例 3：
输入：nums = ["111","011","001"]
输出："101"
解释："101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。
提示：
n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] 为 '0' 或 '1'
nums 中的所有字符串 互不相同
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '0')
                s += '1';
            else
                s += '0';
        }
        return s;
    }
};

//只要和第i个串下标i的字符nums[i][i]不同，构造出来的串就和所有的串都不同。
//只限于串数不超过串长的情况。
//时间复杂度O(n)。

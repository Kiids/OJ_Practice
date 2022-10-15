/*
给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。
特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。
 s 的 子序列可以通过删去字符串 s 中的某些字符实现。
例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
示例 1：
输入: strs = ["aba","cdc","eae"]
输出: 3
示例 2:
输入: strs = ["aaa","aaa","aa"]
输出: -1
提示:
2 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] 只包含小写英文字母
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ret = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            bool flag = 1;
            for (int j = 0; j < strs.size(); j++)
                if (i != j)
                {
                    for (int k = 0, w = 0; k < strs[j].size(); k++)
                    {
                        if (w < strs[i].size() && strs[i][w] == strs[j][k])
                            w++;
                        if (w == strs[i].size())
                            flag = 0;
                }
            }
            if (flag)
                ret = max(ret, (int)strs[i].size());
        }
        return ret;
    }
};

//果答案 res 是 s_i 的子序列但是不是其他字符串的子序列，那么 res=s_i 满足条件。
//所以只需要对每一个字符串检验一遍是否是其他串的子序列。


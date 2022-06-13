/*
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
示例 1：
输入：s = "owoztneoer"
输出："012"
示例 2：
输入：s = "fviefuro"
输出："45"
提示：
1 <= s.length <= 10^5
s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一
s 保证是一个符合题目要求的字符串
*/

class Solution {
public:
    string originalDigits(string s) {
        string ret;
        vector<int> num(10, 0);//通过0-9的英文单词的特征字母来求阿拉伯数字的个数
        vector<int> alpha(26, 0);//字母表 统计每个字母出现的次数
        for (int i = 0; i < s.size(); i++)
            alpha[s[i] - 'a']++;//统计每个字母的数字
        num[0] = alpha['z' - 'a'];
        num[2] = alpha['w' - 'a'];
        num[4] = alpha['u' - 'a'];
        num[6] = alpha['x' - 'a'];
        num[8] = alpha['g' - 'a'];
        num[5] = alpha['f' - 'a'] - num[4];
        num[3] = alpha['h' - 'a'] - num[8];
        num[7] = alpha['s' - 'a'] - num[6];
        num[9] = alpha['i' - 'a'] - num[5] - num[6] - num[8];
        num[1] = alpha['o' - 'a'] - num[0] - num[2] - num[4];

        for (int i = 0; i < 10; i++)
        {
            int count = num[i];
            for (int j = 0; j < count; j++)
                ret.push_back(char('0' + i));
        }
        return ret;
    }
};

/*
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回?dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
示例 1：
输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：
输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
提示：
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s 和 dictionary[i] 仅由小写英文字母组成
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ret;
        for (string d : dictionary)
        {
            int j = 0;
            for (int i = 0; i < s.size() && j < d.size(); i++)
                if (d[j] == s[i])
                    j++;
                    
            if (j == d.size())
            {
                if (d.size() > ret.size())
                    ret = d;
                else if (d.size() == ret.size())
                    ret = d < ret ? d : ret;
            }
        }
        return ret;
    }
};

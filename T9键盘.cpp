/*
在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：
示例 1:
输入: num = "8733", words = ["tree", "used"]
输出: ["tree", "used"]
示例 2:
输入: num = "2", words = ["a", "b", "c", "d"]
输出: ["a", "b", "c"]
提示：
num.length <= 1000
words.length <= 500
words[i].length == num.length
num中不会出现 0, 1 这两个数字
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ret;
        string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = 0;
        string s;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                s = letters[num[j] - '0'];
                if (s.find(words[i][j]) != -1)
                    n++;
            }
            if (n == words[i].size())
                ret.push_back(words[i]);
            n = 0;
        }
        return ret;
    }
};

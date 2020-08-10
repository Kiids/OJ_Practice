/*
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
示例：
输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
注意：
你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s0 = "qwertyuiop";
        string s1 = "asdfghjkl";
        string s2 = "zxcvbnm";
        unordered_map<char, int> m;
        for (char c : s0)
        {
            m[c] = 0;
            m[c - 32] = 0;
        }
        for (char c : s1)
        {
            m[c] = 1;
            m[c - 32] = 1;
        }
        for (char c : s2)
        {
            m[c] = 2;
            m[c - 32] = 2;
        }
        vector<string> ret;
        for (auto& word : words)
        {
            int s = 0;
            for (auto c : word)
                s += m[c];
            if (s == m[word[0]] * word.size())
                ret.push_back(word);
        }
        return ret;
    }
};

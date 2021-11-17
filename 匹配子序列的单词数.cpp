/*
给定字符串 S 和单词字典 words, 求 words[i] 中是 S 的子序列的单词个数。
示例:
输入: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
输出: 3
解释: 有三个是 S 的子序列的单词: "a", "acd", "ace"。
注意:
所有在words和 S 里的单词都只由小写字母组成。
S 的长度在 [1, 50000]。
words 的长度在 [1, 5000]。
words[i]的长度在[1, 50]。
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        for (auto word : words)
        {
            int curindex = -1;
            for (int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                curindex = s.find_first_of(c, curindex + 1);
                if (curindex == string::npos)
                    break;
            }
            ret += curindex >= 0 ? 1 : 0;
        }
        return ret;
    }
};


// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
// 示例 1: 
// 输入: "Let's take LeetCode contest"
// 输出: "s'teL ekat edoCteeL tsetnoc"
// 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
            {
                int j = i;
                for(; j < n && s[j] != ' '; j++);
                reverse(s.begin()+i,s.begin()+j);
                i = j;
            }
        }
        return s;
    }
};


/*
给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。
示例:
输入: "Hello World"
输出: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0, i = s.size() - 1;
        while (i >= 0)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                n++;
            else
                if (n != 0)
                    break;  // 避免最后一个空格
            i--;
        }
        return n;
    }
};

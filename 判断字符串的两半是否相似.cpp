/*
给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。
两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。
如果 a 和 b 相似，返回 true ；否则，返回 false 。
示例 1：
输入：s = "book"
输出：true
解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
示例 2：
输入：s = "textbook"
输出：false
解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
注意，元音 o 在 b 中出现两次，记为 2 个。
示例 3：
输入：s = "MerryChristmas"
输出：false
示例 4：
输入：s = "AbCdEfGh"
输出：true
提示：
2 <= s.length <= 1000
s.length 是偶数
s 由 大写和小写 字母组成
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.size() / 2, suma = 0, sumb = 0;
        string a = s.substr(0,half);
        string b = s.substr(half,half);
        for(int i=0;i<a.size();i++)
        {
            if(a.at(i)=='a'||a.at(i)=='e' ||a.at(i)=='i' ||a.at(i)=='o' ||a.at(i)=='u' ||a.at(i)=='A' ||a.at(i)=='E' ||a.at(i)=='I' ||a.at(i)=='O' ||a.at(i)=='U' )
                suma++;
            if(b.at(i)=='a'||b.at(i)=='e' ||b.at(i)=='i' ||b.at(i)=='o' ||b.at(i)=='u' ||b.at(i)=='A' ||b.at(i)=='E' ||b.at(i)=='I' ||b.at(i)=='O' ||b.at(i)=='U' )
                sumb++;
        }
        if (suma == sumb)
            return true;
        return false;
    }
};

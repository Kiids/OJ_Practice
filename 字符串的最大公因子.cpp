/*
对于字符串 S 和 T，只有在 S = T + ... + T（T 自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
示例 1：
输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：
输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：
输入：str1 = "LEET", str2 = "CODE"
输出：""
提示：
1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while (!str1.empty())
        {
            if (str1 == str2)
                return str1;
            else if (str1.size() > str2.size() && str1.find(str2) == 0)
                str1 = str1.substr(str2.size());
            else if (str1.size() < str2.size() && str2.find(str1) == 0)
                str2 = str2.substr(str1.size());
            else return "";
        }
        return "";
    }
};

// gcd算法（其实就是辗转相除法）:
// int gcd(int a,int b) { return !b? a:gcd(b,a%b); }
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)  ?  str1.substr(0, gcd(str1.size(), str2.size()))  : "";
    }
};

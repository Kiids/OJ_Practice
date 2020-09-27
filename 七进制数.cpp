/*
给定一个整数，将其转化为7进制，并以字符串形式输出。
示例 1:
输入: 100
输出: "202"
示例 2:
输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
            
        bool flag = true;
        if (num < 0)
        {
            flag = false;
            num = -num;
        }

        string ret;
        while (num != 0)
        {
            ret += (char)(num % 7 + '0');
            num /= 7;
        }
        if (!flag)
            ret += '-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// 递归解法
class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0)
            return "-" + convertToBase7(-1 * num);
        if (num < 7)
            return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
}; 

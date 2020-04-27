/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
示例 1:
输入: [10,2]
输出: "102"
示例 2:
输入: [3,30,34,5,9]
输出: "3033459"
提示:
0 < nums.length <= 100
说明:
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
*/


//排成最小的数，则对于两个数x、y，如果x + y < y + x,则x应该排在y之前；反之，若x+y>y+x,则y应排在x之前
class Solution {
public:
    static bool compare(string x, string y)
    {
        return x + y < y + x;
    }
    string minNumber(vector<int>& nums) {
        vector<string> v;
        for (auto i : nums)
            v.push_back(to_string(i));
        sort(v.begin(), v.end(), compare);
        string ret = "";
        for (auto s : v)
            ret += s;
        return ret;
    }
};

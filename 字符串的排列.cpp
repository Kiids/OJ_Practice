/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
限制：
1 <= s 的长度 <= 8
*/

// 回溯法 
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ret;
        if (s.empty())
            return ret;
        
        sort(s.begin(), s.end());
        vector<int> visited(s.size(), 0);
        string str;
        backTrack(ret, s, str, visited);
        return ret;
    }
    void backTrack(vector<string>& ret, string s, string& str, vector<int> v)
    {
        if (str.size() == s.size())  // 回溯结束条件
        {
            ret.push_back(str);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (v[i])
                continue;
            if (i > 0 && !v[i - 1] && s[i - 1] == s[i])
                continue;
            v[i] = 1;

            str.push_back(s[i]);
            backTrack(ret, s, str, v);
            str.pop_back();
            v[i] = 0;
        }
    }
};

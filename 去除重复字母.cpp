/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
示例 1：
输入：s = "bcabc"
输出："abc"
示例 2：
输入：s = "cbacdcbc"
输出："acdb"
提示：
1 <= s.length <= 10^4
s 由小写英文字母组成
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        unordered_set<char> us;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            count[s[i]]++;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            count[c]--;
            if (us.find(c) == us.end())
            {
                while (!st.empty() && st.top() > c && count[st.top()] != 0)
                {
                    us.erase(st.top());
                    st.pop();
                }
                us.emplace(c);
                st.push(c);
            }
        }
        string ret = "";
        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

//如果某个字母之前的某个字母x在之后不再出现了，就不能把这个字母放在x之前
//贪心策略：插入某个字母的时候去和之前的字母逐一比对，之前的字母用一个单调栈维护
//如果发现该字母比之前的字母大或栈空；将该字母放到栈里
//如果字母比之前的字母小，且之前的字母出现了不止一次；将栈顶字母出栈；反复执行；直到栈为空或者不满足条件
//循环退出时，将字母放到栈顶


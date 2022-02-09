/*
����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
ʾ�� 1��
���룺s = "bcabc"
�����"abc"
ʾ�� 2��
���룺s = "cbacdcbc"
�����"acdb"
��ʾ��
1 <= s.length <= 10^4
s ��СдӢ����ĸ���
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

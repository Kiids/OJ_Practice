/*
���� s �ֵ�����С�������У��������а��� s �����в�ͬ�ַ�����ֻ����һ�Ρ�
ʾ�� 1��
���룺s = "bcabc"
�����"abc"
ʾ�� 2��
���룺s = "cbacdcbc"
�����"acdb"
��ʾ��
1 <= s.length <= 1000
s ��СдӢ����ĸ���
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        int st[256];
        unordered_map<char, int> m;
        for (auto c: s)
            m[c]++;
        string ret;
        memset(st, 0, sizeof st);
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]--;
            if (st[s[i]])
                continue;
            while (ret.size() && ret.back() >= s[i] && m[ret.back()])
            {
                st[ret.back()] = false;
                ret.pop_back();
            }
            if (!st[s[i]])
            {
                ret += s[i];
                st[s[i]] = true;
            }
        }
        return ret;
    }
};

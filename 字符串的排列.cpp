/*
����һ���ַ�������ӡ�����ַ������ַ����������С�
�����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�
ʾ��:
���룺s = "abc"
�����["abc","acb","bac","bca","cab","cba"]
���ƣ�
1 <= s �ĳ��� <= 8
*/

// ���ݷ� 
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
        if (str.size() == s.size())  // ���ݽ�������
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

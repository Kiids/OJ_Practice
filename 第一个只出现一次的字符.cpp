/*
���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո�
ʾ��:
s = "abaccdeff"
���� "b"
s = "" 
���� " "
���ƣ�
0 <= s �ĳ��� <= 50000
*/

class Solution {
public:
    char firstUniqChar(string s) {
        /*if (s.size() <= 1)
            return (char)s.c_str();*/

        int hash[256] = {0};
        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1)
            {
                return s[i];
            }
        }

        return ' ';
    }
};

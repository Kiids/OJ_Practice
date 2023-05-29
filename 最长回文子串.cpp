/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����
ʾ�� 1��
���룺s = "babad"
�����"bab"
���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
ʾ�� 2��
���룺s = "cbbd"
�����"bb"
��ʾ��
1 <= s.length <= 1000
s �������ֺ�Ӣ����ĸ���
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        string ret;
        for (int i = 0; i < n - 1; i++)
        {
            if (i + 1 < n && s[i + 1] == s[i])  // �����Ĵ�ż������
            {
                int l = i, r = i + 1;
                while (l >= 0 && r < n)
                {
                    if (s[l] != s[r])           // ������ֹ
                        break;
                    r++;
					l--;
                }
                if (r - l - 1 > ret.size())
                    ret = s.substr(l + 1, r - l - 1);
            }
            if (i > 0 && s[i - 1] == s[i + 1])  // �����Ĵ���������
            {
                int l = i - 1, r = i + 1;
                while (l >= 0 && r < n)
                {
                    if (s[l] != s[r])           // ������ֹ
                        break;
                    r++;
                    l--;
                }
                if (r - l - 1 > ret.size())
                    ret = s.substr(l + 1, r - l - 1);
            }
        }
        return ret.size() == 0 ? ret + s[0] : ret;
    }
};

/*
����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���
�ڹ�������У���ע�����ִ�Сд������ "Aa" ���ܵ���һ�������ַ�����
ע��:
�����ַ����ĳ��Ȳ��ᳬ�� 1010��
ʾ�� 1:
����:
"abccccdd"
���:
7
����:
���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int v[52] = {0}, ret = 0;
        bool flag = false;
        for (char& c : s)
        {
            if ('A' <= c && c <= 'Z')
                v[c - 'A']++;
            else
                v[c - 'a' + 26]++;
        }
        for (int i = 0; i < 52; i++)
        {
            if (v[i] % 2 == 0)
                ret += v[i];
            else if (flag == false)
            {
                flag = true;
                ret += v[i];
            } 
            else
                ret += v[i] - 1;
        }
        return ret;
    }
};

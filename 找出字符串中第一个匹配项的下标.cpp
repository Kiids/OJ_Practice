/*
���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻�  -1 ��
ʾ�� 1��
���룺haystack = "sadbutsad", needle = "sad"
�����0
���ͣ�"sad" ���±� 0 �� 6 ��ƥ�䡣
��һ��ƥ������±��� 0 �����Է��� 0 ��
ʾ�� 2��
���룺haystack = "leetcode", needle = "leeto"
�����-1
���ͣ�"leeto" û���� "leetcode" �г��֣����Է��� -1 ��
��ʾ��
1 <= haystack.length, needle.length <= 10^4
haystack �� needle ����СдӢ���ַ����
*/

class Solution {
    void getNext(int* next, const string& s)  // ��� next ����
    {
        int j = 0;
        next[0] = 0;  // ǰ׺�����Ԫ�� 0 ���ַ�������λû�ж�Ӧ��ǰ׺
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        int next[needle.size()];  // ���� next ���� - ǰ׺��
        getNext(next, needle);  // ���ǰ׺��
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};

/*
����һ���ַ��� s ����ֻ���������ַ� a, b �� c ��
���㷵�� a��b �� c �� ���� ���ֹ�һ�ε����ַ�����Ŀ��
ʾ�� 1��
���룺s = "abcabc"
�����10
���ͣ����� a��b �� c ������һ�ε����ַ���Ϊ "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" �� "abc" (��ͬ�ַ�������)��
ʾ�� 2��
���룺s = "aaacb"
�����3
���ͣ����� a��b �� c ������һ�ε����ַ���Ϊ "aaacb", "aacb" �� "acb" ��
ʾ�� 3��
���룺s = "abc"
�����1
��ʾ��
3 <= s.length <= 5 x 10^4
s ֻ�����ַ� a��b �� c ��
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ret = 0, a = -1, b = -1, c = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                a = i;
                ret += min(b, c) + 1;
            }
            else if (s[i] == 'b')
            {
                b = i;
                ret += min(a, c) + 1;
            }
            else
            {
                c = i;
                ret += min(a, b) + 1;
            }
        }
        return ret;
    }
};

/*
һ���ַ������û�� �������� ��ͬ�ַ�����ô������һ�� ���ַ��� ��
����һ���ַ��� s ������� s ɾ�� ���� ���ַ���ʹ�����һ�� ���ַ��� ��
���㷵��ɾ������ַ�������Ŀ���ݱ�֤������ Ψһ�� ��
ʾ�� 1��
���룺s = "leeetcode"
�����"leetcode"
���ͣ�
�ӵ�һ�� 'e' ����ɾ��һ�� 'e' ���õ� "leetcode" ��
û������������ͬ�ַ������Է��� "leetcode" ��
ʾ�� 2��
���룺s = "aaabaaaa"
�����"aabaa"
���ͣ�
�ӵ�һ�� 'a' ����ɾ��һ�� 'a' ���õ� "aabaaaa" ��
�ӵڶ��� 'a' ����ɾ������ 'a' ���õ� "aabaa" ��
û������������ͬ�ַ������Է��� "aabaa" ��
ʾ�� 3��
���룺s = "aab"
�����"aab"
���ͣ�û������������ͬ�ַ������Է��� "aab" ��
��ʾ��
1 <= s.length <= 10^5
s ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    string makeFancyString(string s) {
        string ret = "";
        char t = ' ';
        int flag = 1;
        for (char& c : s)
        {
            if (c != t)
            {
                ret += c;
                t = c;
                flag = 1;
            }
            else
            {
                flag++;
                if (flag < 3)
                    ret += c;
            }
        }
        return ret;
    }
};

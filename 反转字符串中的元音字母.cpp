/*
��дһ�����������ַ�����Ϊ���룬��ת���ַ����е�Ԫ����ĸ��
ʾ�� 1��
���룺"hello"
�����"holle"
ʾ�� 2��
���룺"leetcode"
�����"leotcede"
��ʾ��
Ԫ����ĸ��������ĸ "y" ��
*/

class Solution {
public:
    string reverseVowels(string s) {
        string v = "aeiouAEIOU";
        int i = -1, j = s.size();
        while (i < j)
        {
            while (i < j && v.find(s[++i]) == v.npos);
            while (i < j && v.find(s[--j]) == v.npos);
            swap(s[i], s[j]);
        }
        return s;
    }
};

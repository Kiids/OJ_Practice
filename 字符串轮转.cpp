/*
�ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������
ʾ��1:
 ���룺s1 = "waterbottle", s2 = "erbottlewat"
 �����True
ʾ��2:
 ���룺s1 = "aa", "aba"
 �����False
��ʾ��
�ַ���������[0, 100000]��Χ�ڡ�
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;
    }
};

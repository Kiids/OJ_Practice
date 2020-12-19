/*
�����ַ��� S �� T��ֻ���� S = T + ... + T��T �������� 1 �λ��Σ�ʱ�����ǲ��϶� ��T �ܳ��� S����
������ַ��� X��Ҫ������ X �ܳ��� str1 �� X �ܳ��� str2��
ʾ�� 1��
���룺str1 = "ABCABC", str2 = "ABC"
�����"ABC"
ʾ�� 2��
���룺str1 = "ABABAB", str2 = "ABAB"
�����"AB"
ʾ�� 3��
���룺str1 = "LEET", str2 = "CODE"
�����""
��ʾ��
1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] �� str2[i] Ϊ��дӢ����ĸ
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while (!str1.empty())
        {
            if (str1 == str2)
                return str1;
            else if (str1.size() > str2.size() && str1.find(str2) == 0)
                str1 = str1.substr(str2.size());
            else if (str1.size() < str2.size() && str2.find(str1) == 0)
                str2 = str2.substr(str1.size());
            else return "";
        }
        return "";
    }
};

// gcd�㷨����ʵ����շת�������:
// int gcd(int a,int b) { return !b? a:gcd(b,a%b); }
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)  ?  str1.substr(0, gcd(str1.size(), str2.size()))  : "";
    }
};

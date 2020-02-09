/*
����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
ʾ�� 1��
���룺"ab-cd"
�����"dc-ba"
ʾ�� 2��
���룺"a-bC-dEf-ghIj"
�����"j-Ih-gfE-dCba"
ʾ�� 3��
���룺"Test1ng-Leet=code-Q!"
�����"Qedo1ct-eeLg=ntse-T!"
��ʾ��
S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S �в����� \ or "
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S == "" || S.size() <= 1)
            return S;

        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            while (i < j && !isLetters(S[i]))
                i++;
            while (i < j && !isLetters(S[j]))
                j--;
            if (i < j)
            {
                char t = S[i];
                S[i] = S[j];
                S[j] = t;
                i++;
                j--;
            }
        }
        return S;
    }
    bool isLetters(char c)
    {
        if (c >= 'a' && c <= 'z')
            return true;
        else if (c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    }
};

/*
����һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����
ʾ�� 1:
����: "aba"
���: True
ʾ�� 2:
����: "abca"
���: True
����: �����ɾ��c�ַ���
ע��:
�ַ���ֻ������ a-z ��Сд��ĸ���ַ�������󳤶���50000��
*/

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 0)
            return true;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
                l++, r--;
            else
                return isValid(s, l + 1, r) || isValid(s, l, r - 1);
        }
        return true;
    }

    bool isValid(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] == s[r])
                l++, r--;
            else
                return false;
        }
        return true;
    }
};

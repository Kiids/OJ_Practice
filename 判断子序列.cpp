/*
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
���ף�
����д�������� S������ S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿
ʾ�� 1��
���룺s = "abc", t = "ahbgdc"
�����true
ʾ�� 2��
���룺s = "axc", t = "ahbgdc"
�����false
��ʾ��
0 <= s.length <= 100
0 <= t.length <= 10^4
�����ַ�����ֻ��Сд�ַ���ɡ�
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = 0, index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = index; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    n++;
                    index = j + 1;
                    break;
                }
            }
        }
        if (n == s.size())
            return true;
        else
            return false;
    }
};

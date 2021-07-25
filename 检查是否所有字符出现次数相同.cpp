/*
����һ���ַ��� s ����� s ��һ�� �� �ַ��������㷵�� true �������뷵�� false ��
��� s �г��ֹ��� ���� �ַ��ĳ��ִ��� ��ͬ ����ô���ǳ��ַ��� s �� �� �ַ�����
ʾ�� 1��
���룺s = "abacbc"
�����true
���ͣ�s �г��ֹ����ַ�Ϊ 'a'��'b' �� 'c' ��s �������ַ������� 2 �Ρ�
ʾ�� 2��
���룺s = "aaabb"
�����false
���ͣ�s �г��ֹ����ַ�Ϊ 'a' �� 'b' ��
'a' ������ 3 �Σ�'b' ������ 2 �Σ����߳��ִ�����ͬ��
��ʾ��
1 <= s.length <= 1000
s ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        for (auto& c : s)
            m[c]++;
        int x = m[s[0]];
        for (int i = 0; i < s.size(); i++)
            if (x != m[s[i]])
                return false;
        return true;
    }
};

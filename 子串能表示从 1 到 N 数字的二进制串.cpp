/*
����һ���������ַ��� s ��һ�������� n��������� [1, n] ��Χ�ڵ�ÿ��������������Ʊ�ʾ���� s �� ���ַ��� ���ͷ��� true�����򷵻� false ��
���ַ��� ���ַ������������ַ����С�
ʾ�� 1��
���룺s = "0110", n = 3
�����true
ʾ�� 2��
���룺s = "0110", n = 4
�����false
��ʾ��
1 <= s.length <= 1000
s[i] ���� '0' ���� '1'
1 <= n <= 10^9
*/

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> set;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                continue;
            int cur = 0;
            for (int j = i; j < s.size(); j++)
            {
                cur = cur * 2 + s[j] - '0';
                if (cur > n)
                    break;
                set.insert(cur);
            }
        }
        return set.size() == n;
    }
};

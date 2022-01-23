/*
�����ַ��� s ������ k ��
�뷵���ַ��� s �г���Ϊ k �ĵ������ַ����п��ܰ��������Ԫ����ĸ����
Ӣ���е� Ԫ����ĸ Ϊ��a, e, i, o, u����
ʾ�� 1��
���룺s = "abciiidef", k = 3
�����3
���ͣ����ַ��� "iii" ���� 3 ��Ԫ����ĸ��
ʾ�� 2��
���룺s = "aeiou", k = 2
�����2
���ͣ����ⳤ��Ϊ 2 �����ַ��������� 2 ��Ԫ����ĸ��
ʾ�� 3��
���룺s = "leetcode", k = 3
�����2
���ͣ�"lee"��"eet" �� "ode" ������ 2 ��Ԫ����ĸ��
ʾ�� 4��
���룺s = "rhythms", k = 4
�����0
���ͣ��ַ��� s �в����κ�Ԫ����ĸ��
ʾ�� 5��
���룺s = "tryhard", k = 4
�����1
��ʾ��
1 <= s.length <= 10^5
s ��СдӢ����ĸ���
1 <= k <= s.length
*/

class Solution {
    bool Fun(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int n = 0;
        for (int i = 0; i < k; i++)
            n += Fun(s[i]);

        int ret = n;
        for (int i = k; i < s.size(); i++)
        {
            if (Fun(s[i - k]))
                n--;
            n += Fun(s[i]);
            ret = max(ret, n);
        }
        return ret;
    }
};

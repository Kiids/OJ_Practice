/*
���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
��λ�� ָ��ĸ��ͬ�������в�ͬ���ַ�����
ʾ�� 1:
����: s = "cbaebabacd", p = "abc"
���: [0,6]
����:
��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����λ�ʡ�
��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����λ�ʡ�
 ʾ�� 2:
����: s = "abab", p = "ab"
���: [0,1,2]
����:
��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����λ�ʡ�
��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʾ:
1 <= s.length, p.length <= 3 * 104
s �� p ������Сд��ĸ
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n)
            return {};
        vector<int> v, ns(26), np(26);  // ��ϣ��¼������ĸ���� 
        int i;
        for (i = 0; i < m; i++)
        {
            np[p[i] - 'a']++;
            ns[s[i] - 'a']++;
        }
        if (np == ns)
            v.push_back(0);
        for (; i < n; i++)              // �����Ƚ� 
        {
            ns[s[i] - 'a']++;
            ns[s[i - m] - 'a']--;
            if (np == ns)
                v.push_back(i - m + 1);
        }
        return v;
    }
};

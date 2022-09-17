/*
����һ���ַ��� s �������ָ��ַ����������ز�ֺ�Ψһ���ַ����������Ŀ��
�ַ��� s ��ֺ���Եõ����� �ǿ����ַ��� ����Щ���ַ������Ӻ�Ӧ���ܹ���ԭΪԭ�ַ��������ǲ�ֳ�����ÿ�����ַ����������� Ψһ�� ��
ע�⣺���ַ��� ���ַ����е�һ�������ַ����С�
ʾ�� 1��
���룺s = "ababccc"
�����5
���ͣ�һ������ַ���Ϊ ['a', 'b', 'ab', 'c', 'cc'] ���� ['a', 'b', 'a', 'b', 'c', 'cc'] ������ֲ�������ĿҪ����Ϊ���е� 'a' �� 'b' �������˲�ֹһ�Ρ�
ʾ�� 2��
���룺s = "aba"
�����2
���ͣ�һ������ַ���Ϊ ['a', 'ba'] ��
ʾ�� 3��
���룺s = "aa"
�����1
���ͣ��޷���һ������ַ�����
��ʾ��
1 <= s.length <= 16
*/

class Solution {
    int ret = 0;
    unordered_set<string> us;
    void DFS(string& s, int pos)
    {
        if (s.size() - pos + us.size() <= ret)
            return;
        if (pos == s.size())
        {
            ret = max(ret, (int)us.size());
            return;
        }

        string t;
        for (int i = pos; i < s.size(); i++)
		{
            t += s[i];
            if (us.find(t) == us.end())
            {
                us.insert(t);
                DFS(s, i + 1);
                us.erase(t);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        DFS(s, 0);
        return ret;
    }
};

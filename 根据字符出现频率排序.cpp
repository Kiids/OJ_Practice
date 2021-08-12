/*
����һ���ַ������뽫�ַ�������ַ����ճ��ֵ�Ƶ�ʽ������С�
ʾ�� 1:
����:
"tree"
���:
"eert"
����:
'e'�������Σ�'r'��'t'��ֻ����һ�Ρ�
���'e'���������'r'��'t'֮ǰ�����⣬"eetr"Ҳ��һ����Ч�Ĵ𰸡�
ʾ�� 2:
����:
"cccaaa"
���:
"cccaaa"
����:
'c'��'a'���������Ρ����⣬"aaaccc"Ҳ����Ч�Ĵ𰸡�
ע��"cacaca"�ǲ���ȷ�ģ���Ϊ��ͬ����ĸ�������һ��
ʾ�� 3:
����:
"Aabb"
���:
"bbAa"
����:
���⣬"bbaA"Ҳ��һ����Ч�Ĵ𰸣���"Aabb"�ǲ���ȷ�ġ�
ע��'A'��'a'����Ϊ�����ֲ�ͬ���ַ���
*/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        string ret = "";
        for (auto& c : s)
            m[c]++;
        while (!m.empty())
        {
            auto pos = m.begin();
            for (auto i = m.begin(); i != m.end(); i++)
                if (i->second > pos->second)
                    pos = i;
            ret.insert(ret.size(), pos->second, pos->first);
            m.erase(pos);
        }
        return ret;
    }
};

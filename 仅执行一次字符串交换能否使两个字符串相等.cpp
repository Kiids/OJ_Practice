/*
���㳤����ȵ������ַ��� s1 �� s2 ��һ�� �ַ������� �����Ĳ������£�ѡ��ĳ���ַ����е������±꣨���ز�ͬ�����������������±�����Ӧ���ַ���
����� ����һ���ַ��� ִ�� ���һ���ַ������� �Ϳ���ʹ�����ַ�����ȣ����� true �����򣬷��� false ��
ʾ�� 1��
���룺s1 = "bank", s2 = "kanb"
�����true
���ͣ����磬���� s2 �еĵ�һ�������һ���ַ����Եõ� "bank"
ʾ�� 2��
���룺s1 = "attack", s2 = "defend"
�����false
���ͣ�һ���ַ��������޷�ʹ�����ַ������
ʾ�� 3��
���룺s1 = "kelb", s2 = "kelb"
�����true
���ͣ������ַ����Ѿ���ȣ����Բ���Ҫ�����ַ�������
ʾ�� 4��
���룺s1 = "abcd", s2 = "dcba"
�����false
��ʾ��
1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 �� s2 ����СдӢ����ĸ���
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> v;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                v.push_back(i);
        if (v.size() == 0)
            return true;
        else if (v.size() == 2)
        {
            swap(s1[v[0]], s1[v[1]]);
            return s1 == s2;
        }
        return false;
    }
};

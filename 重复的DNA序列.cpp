/*
DNA���� ��һϵ�к�������ɣ���дΪ 'A', 'C', 'G' �� 'T'.��
���磬"ACGAATTCCG" ��һ�� DNA���� ��
���о� DNA ʱ��ʶ�� DNA �е��ظ����зǳ����á�
����һ����ʾ DNA���� ���ַ��� s ������������ DNA �����г��ֲ�ֹһ�ε� ����Ϊ 10 ������(���ַ���)������԰� ����˳�� ���ش𰸡�
ʾ�� 1��
���룺s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
�����["AAAAACCCCC","CCCCCAAAAA"]
ʾ�� 2��
���룺s = "AAAAAAAAAAAAA"
�����["AAAAAAAAAA"]
��ʾ��
0 <= s.length <= 10^5
s[i]=='A'��'C'��'G' or 'T'
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st;
        int n = s.size();
        vector<string> v;
        for (int i = 0; i + 10 <= n; i++)
        {
            string t = s.substr(i, 10);
            if (st.count(t))
                v.push_back(t);
            else
                st.insert(t);
        }

        sort(v.begin(), v.end());
        // it ��������unique�������ظ����ֵ�Ԫ�طŵ�����ĩβ,�������ⲿ��Ԫ�ص�һ�����ֵ�λ�ã����մӸ�λ�ÿ�ʼɾ����������Ԫ�ؼ���
        auto it = unique(v.begin(), v.end());
        v.erase(it, v.end());
        return v;
    }
};

//����һ������ set ���ϣ�� unordered_map ��¼һ���ַ�������������ֵĴ���
//�����ַ���������ǰλ�� i ��ͷ�ĳ���Ϊ 10 �����ַ��������ֹ�������������顣���򽫸����ַ������뼯�ϻ��ϣ��
//���ڿ��ܳ���ĳһ�����ַ�����γ��֣�ÿ�ζ������������飬���Խ������ȥ�ء�

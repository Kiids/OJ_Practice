/*
����һ���ַ��� s����k ���ظ���ɾ������������� s ��ѡ�� k ����������ȵ���ĸ����ɾ�����ǣ�ʹ��ɾȥ���ַ����������Ҳ�����һ��
����Ҫ�� s �ظ��������޴�������ɾ��������ֱ���޷�����Ϊֹ��
��ִ��������ɾ�������󣬷������յõ����ַ�����
����𰸱�֤Ψһ��
ʾ�� 1��
���룺s = "abcd", k = 2
�����"abcd"
���ͣ�û��Ҫɾ�������ݡ�
ʾ�� 2��
���룺s = "deeedbbcccbdaa", k = 3
�����"aa"
���ͣ� 
��ɾ�� "eee" �� "ccc"���õ� "ddbbbdaa"
��ɾ�� "bbb"���õ� "dddaa"
���ɾ�� "ddd"���õ� "aa"
ʾ�� 3��
���룺s = "pbbcggttciiippooaais", k = 2
�����"ps"
��ʾ��
1 <= s.length <= 10^5
2 <= k <= 10^4
s ��ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int> > st;
        for (auto& i : s)
        {
            if (!st.empty() && st.back().first == i)
            {
                if (++st.back().second == k)
                    st.pop_back();
            }
            else
                st.push_back(make_pair(i, 1));
        }
        string ret;
        for (auto& i : st)
        {
            int l = i.second;
            while (l--)
                ret += i.first;
        }
        return ret;
    }
};

/*
����һ������ f(s)��ͳ�� s  �У����ֵ���Ƚϣ���С��ĸ�ĳ���Ƶ�� ������ s ��һ���ǿ��ַ�����
���磬�� s = "dcce"����ô f(s) = 2����Ϊ�ֵ�����С��ĸ�� "c"���������� 2 �Ρ�
���ڣ����������ַ����������� queries �ʹʻ�� words ������ÿ�β�ѯ queries[i] ����ͳ�� words ������ f(queries[i]) < f(W) �� �ʵ���Ŀ ��W ��ʾ�ʻ�� words �е�ÿ���ʡ�
���㷵��һ���������� answer ��Ϊ�𰸣�����ÿ�� answer[i] �ǵ� i �β�ѯ�Ľ����
ʾ�� 1��
���룺queries = ["cbd"], words = ["zaaaz"]
�����[1]
���ͣ���ѯ f("cbd") = 1���� f("zaaaz") = 3 ���� f("cbd") < f("zaaaz")��
ʾ�� 2��
���룺queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
�����[1,2]
���ͣ���һ����ѯ f("bbb") < f("aaaa")���ڶ�����ѯ f("aaa") �� f("aaaa") �� > f("cc")��
��ʾ��
1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j]��words[i][j] ����СдӢ����ĸ���
*/

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> flag, ret;
        for (auto e : words)
        {
            map<char, int> m;
            for (auto i : e)
                m[i]++;
            int t = m.begin()->second;
            flag.emplace_back(t);
        }
        for (auto e : queries)
        {
            map<char, int> m;
            int sum = 0;
            for (auto i : e)
                m[i]++;
            int t = m.begin()->second;
            for (auto i : flag)
                if (t < i)
            sum++;
            ret.emplace_back(sum);
        }
        return ret;
    }
};

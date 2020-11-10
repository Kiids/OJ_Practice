/*
������������ A �� B �� ��������һ���ɿո�ָ��ĵ��ʡ�ÿ�����ʽ���Сд��ĸ��ɡ���
���һ������������һ��������ֻ����һ�Σ�����һ��������ȴû�г��֣���ô������ʾ��ǲ������ġ�
�������в����õ��ʵ��б�
�����԰��κ�˳�򷵻��б�
ʾ�� 1��
���룺A = "this apple is sweet", B = "this apple is sour"
�����["sweet","sour"]
ʾ�� 2��
���룺A = "apple apple", B = "banana"
�����["banana"]
��ʾ��
0 <= A.length <= 200
0 <= B.length <= 200
A �� B ��ֻ�����ո��Сд��ĸ��
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        stringstream a(A), b(B);
        string w;
        while (a >> w)
            m[w]++;
        while (b >> w)
            m[w]++;
        vector<string> ret;
        for (auto e : m)
            if (e.second == 1)
                ret.emplace_back(e.first);
        return ret;
    }
};

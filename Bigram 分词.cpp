/*
������һ���� first �͵ڶ����� second��������ĳЩ�ı� text �п����� "first second third" ��ʽ���ֵ���������� second ���� first ���֣�third ���� second ���֡�
����ÿ����������������������� "third" ��ӵ����У������ش𰸡�
ʾ�� 1��
���룺text = "alice is a good girl she is a good student", first = "a", second = "good"
�����["girl","student"]
ʾ�� 2��
���룺text = "we will we will rock you", first = "we", second = "will"
�����["we","rock"]
��ʾ��
1 <= text.length <= 1000
text ��һЩ�ÿո�ָ��ĵ�����ɣ�ÿ�����ʶ���СдӢ����ĸ���
1 <= first.length, second.length <= 10
first �� second ��СдӢ����ĸ���
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream words(text);
        string w;
        vector<string> tmp, ret;
        while (words >> w)
            tmp.push_back(w);
        for (int i = 0, j = 1; j < tmp.size() - 1; i++, j++) 
            if (tmp[i] == first && tmp[j] == second)
                ret.push_back(tmp[j + 1]);
        return ret;
    }
};

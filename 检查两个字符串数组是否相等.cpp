/*
���������ַ������� word1 �� word2 ��������������ʾ���ַ�����ͬ������ true �����򣬷��� false ��
�����ʾ���ַ��� ���������е�����Ԫ�� ��˳�� �����γɵ��ַ�����
ʾ�� 1��
���룺word1 = ["ab", "c"], word2 = ["a", "bc"]
�����true
���ͣ�
word1 ��ʾ���ַ���Ϊ "ab" + "c" -> "abc"
word2 ��ʾ���ַ���Ϊ "a" + "bc" -> "abc"
�����ַ�����ͬ������ true
ʾ�� 2��
���룺word1 = ["a", "cb"], word2 = ["ab", "c"]
�����false
ʾ�� 3��
���룺word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
�����true
��ʾ��
1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] �� word2[i] ��Сд��ĸ���
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for (auto e : word1)
            a += e;
        for (auto e : word2)
            b += e;
        return a == b;
    }
};

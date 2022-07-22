/*
����һ���ַ������� patterns ��һ���ַ��� word ��ͳ�� patterns ���ж��ٸ��ַ����� word �����ַ����������ַ�����Ŀ��
���ַ��� ���ַ����е�һ�������ַ����С�
ʾ�� 1��
���룺patterns = ["a","abc","bc","d"], word = "abc"
�����3
���ͣ�
- "a" �� "abc" �����ַ�����
- "abc" �� "abc" �����ַ�����
- "bc" �� "abc" �����ַ�����
- "d" ���� "abc" �����ַ�����
patterns ���� 3 ���ַ�����Ϊ���ַ��������� word �С�
ʾ�� 2��
���룺patterns = ["a","b","c"], word = "aaaaabbbbb"
�����2
���ͣ�
- "a" �� "aaaaabbbbb" �����ַ�����
- "b" �� "aaaaabbbbb" �����ַ�����
- "c" ���� "aaaaabbbbb" ���ַ�����
patterns ���� 2 ���ַ�����Ϊ���ַ��������� word �С�
ʾ�� 3��
���룺patterns = ["a","a","a"], word = "ab"
�����3
���ͣ�patterns �е�ÿ���ַ�������Ϊ���ַ��������� word "ab" �С�
��ʾ��
1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] �� word ��СдӢ����ĸ���
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ret = 0;
        for (auto& e : patterns)
            if (word.find(e) != -1)
                ret++;
        return ret;
    }
};

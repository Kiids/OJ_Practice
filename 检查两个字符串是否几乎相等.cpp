/*
��������ַ��� word1 �� word2 �д� 'a' �� 'z' ÿһ����ĸ����Ƶ��֮� ������ 3 ����ô���ǳ��������ַ��� word1 �� word2 ������� ��
�����������ȶ�Ϊ n ���ַ��� word1 �� word2 ����� word1 �� word2 ������� �����㷵�� true �����򷵻� false ��
һ����ĸ x �ĳ��� Ƶ�� ָ���������ַ����г��ֵĴ�����
ʾ�� 1��
���룺word1 = "aaaa", word2 = "bccb"
�����false
���ͣ��ַ��� "aaaa" ���� 4 �� 'a' ������ "bccb" ���� 0 �� 'a' ��
����֮��Ϊ 4 ���������� 3 ��
ʾ�� 2��
���룺word1 = "abcdeef", word2 = "abaaacc"
�����true
���ͣ�word1 �� word2 ��ÿ����ĸ����Ƶ��֮������Ϊ 3 ��
- 'a' �� word1 �г����� 1 �Σ��� word2 �г����� 4 �Σ���Ϊ 3 ��
- 'b' �� word1 �г����� 1 �Σ��� word2 �г����� 1 �Σ���Ϊ 0 ��
- 'c' �� word1 �г����� 1 �Σ��� word2 �г����� 2 �Σ���Ϊ 1 ��
- 'd' �� word1 �г����� 1 �Σ��� word2 �г����� 0 �Σ���Ϊ 1 ��
- 'e' �� word1 �г����� 2 �Σ��� word2 �г����� 0 �Σ���Ϊ 2 ��
- 'f' �� word1 �г����� 1 �Σ��� word2 �г����� 0 �Σ���Ϊ 1 ��
ʾ�� 3��
���룺word1 = "cccddabba", word2 = "babababab"
�����true
���ͣ�word1 �� word2 ��ÿ����ĸ����Ƶ��֮������Ϊ 3 ��
- 'a' �� word1 �г����� 2 �Σ��� word2 �г����� 4 �Σ���Ϊ 2 ��
- 'b' �� word1 �г����� 2 �Σ��� word2 �г����� 5 �Σ���Ϊ 3 ��
- 'c' �� word1 �г����� 3 �Σ��� word2 �г����� 0 �Σ���Ϊ 3 ��
- 'd' �� word1 �г����� 2 �Σ��� word2 �г����� 0 �Σ���Ϊ 2 ��
��ʾ��
n == word1.length == word2.length
1 <= n <= 100
word1 �� word2 ��ֻ����СдӢ����ĸ��
*/

class Solution {
    int v[2][27];
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        for (auto& c : word1)
            v[0][c - 'a']++;
        for (auto& c : word2)
            v[1][c - 'a']++;
        for (int i = 0; i < 27; i++) 
            if (abs(v[0][i] - v[1][i]) > 3)
                return false;
        return true;
    }
};

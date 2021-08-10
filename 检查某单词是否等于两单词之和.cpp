/*
��ĸ�� ��ĸֵ ȡ������ĸ����ĸ���е�λ�ã��� 0 ��ʼ ����������'a' -> 0��'b' -> 1��'c' -> 2���Դ����ơ�
��ĳ����Сд��ĸ��ɵ��ַ��� s ���ԣ��� ��ֵ �͵��ڽ� s ��ÿ����ĸ�� ��ĸֵ ��˳�� ���� �� ת�� �ɶ�Ӧ������
���磬s = "acb" ����������ÿ����ĸ����ĸֵ���Եõ� "021" ��ת��Ϊ�����õ� 21 ��
���������ַ��� firstWord��secondWord �� targetWord ��ÿ���ַ������ɴ� 'a' �� 'j' ���� 'a' �� 'j' ����СдӢ����ĸ��ɡ�
��� firstWord �� secondWord �� ��ֵ֮�� ���� targetWord ����ֵ������ true �����򣬷��� false ��
ʾ�� 1��
���룺firstWord = "acb", secondWord = "cba", targetWord = "cdb"
�����true
���ͣ�
firstWord ����ֵΪ "acb" -> "021" -> 21
secondWord ����ֵΪ "cba" -> "210" -> 210
targetWord ����ֵΪ "cdb" -> "231" -> 231
���� 21 + 210 == 231 ������ true
ʾ�� 2��
���룺firstWord = "aaa", secondWord = "a", targetWord = "aab"
�����false
���ͣ�
firstWord ����ֵΪ "aaa" -> "000" -> 0
secondWord ����ֵΪ "a" -> "0" -> 0
targetWord ����ֵΪ "aab" -> "001" -> 1
���� 0 + 0 != 1 ������ false
ʾ�� 3��
���룺firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
�����true
���ͣ�
firstWord ����ֵΪ "aaa" -> "000" -> 0
secondWord ����ֵΪ "a" -> "0" -> 0
targetWord ����ֵΪ "aaaa" -> "0000" -> 0
���� 0 + 0 == 0 ������ true
��ʾ��
1 <= firstWord.length, secondWord.length, targetWord.length <= 8
firstWord��secondWord �� targetWord ���ɴ� 'a' �� 'j' ����?'a' �� 'j' ����СдӢ����ĸ��ɡ�
*/

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return fun(firstWord) + fun(secondWord) == fun(targetWord);
    }

    int fun(string s)
    {
        int ret = 0;
        for (char & c : s)
            ret = ret * 10 + (c - 'a');
        return ret;
    }
};

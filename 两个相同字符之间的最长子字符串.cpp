/*
����һ���ַ��� s�����㷵�� ������ͬ�ַ�֮�������ַ����ĳ��� �����㳤��ʱ�����������ַ���������������������ַ��������� -1 ��
���ַ��� ���ַ����е�һ�������ַ����С�
ʾ�� 1��
���룺s = "aa"
�����0
���ͣ����ŵ����ַ��������� 'a' ֮��Ŀ����ַ�����
ʾ�� 2��
���룺s = "abca"
�����2
���ͣ����ŵ����ַ����� "bc" ��
ʾ�� 3��
���룺s = "cbzxy"
�����-1
���ͣ�s �в����ڳ��ֳ������ε��ַ������Է��� -1 ��
ʾ�� 4��
���룺s = "cabbac"
�����4
���ͣ����ŵ����ַ����� "abba" �������ķ����Ž���� "bb" �� "" ��
��ʾ��
1 <= s.length <= 300
s ֻ��СдӢ����ĸ
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26, -1);
        int maxlen = -1;
        for (int i = 0; i < s.size(); i++) 
        {
            int index = s[i] - 'a';
            if (v[index] == -1)
                v[index] = i;
            else
                maxlen = max(maxlen, i - v[index] - 1);
        }
        return maxlen;
    }
};

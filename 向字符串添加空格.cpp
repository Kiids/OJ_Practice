/*
����һ���±�� 0 ��ʼ���ַ��� s ���Լ�һ���±�� 0 ��ʼ���������� spaces ��
���� spaces ����ԭ�ַ�������Ҫ��ӿո���±ꡣÿ���ո�Ӧ�ò��뵽�������������ַ�ֵ ֮ǰ ��
���磬s = "EnjoyYourCoffee" �� spaces = [5, 9] ����ô������Ҫ�� 'Y' �� 'C' ֮ǰ��ӿո��������ַ��ֱ�λ���±� 5 ���±� 9 ����ˣ����յõ� "Enjoy Your Coffee" ��
������ӿո񣬲������޸ĺ���ַ�����
ʾ�� 1��
���룺s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
�����"Leetcode Helps Me Learn"
���ͣ�
�±� 8��13 �� 15 ��Ӧ "LeetcodeHelpsMeLearn" �мӴ�б���ַ���
��������Щ�ַ�ǰ��ӿո�
ʾ�� 2��
���룺s = "icodeinpython", spaces = [1,5,7,9]
�����"i code in py thon"
���ͣ�
�±� 1��5��7 �� 9 ��Ӧ "icodeinpython" �мӴ�б���ַ���
��������Щ�ַ�ǰ��ӿո�
ʾ�� 3��
���룺s = "spacing", spaces = [0,1,2,3,4,5,6]
�����" s p a c i n g"
���ͣ�
�ַ����ĵ�һ���ַ�ǰ������ӿո�
��ʾ��
1 <= s.length <= 3 * 10^5
s ���ɴ�СдӢ����ĸ���
1 <= spaces.length <= 3 * 10^5
0 <= spaces[i] <= s.length - 1
spaces �е�����ֵ �ϸ����
*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        int n = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (n == spaces.size() || i != spaces[n])
            {
                str += s[i];
                continue;
            }
            if (i == spaces[n])
            {
                str += " ";
                str += s[i];
                n++;
                continue;
            }
        }
        return str;
    }
};

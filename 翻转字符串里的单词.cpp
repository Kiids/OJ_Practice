/*
����һ���ַ��� s �������ת�ַ����е����� ���� ��
���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
���㷵��һ����ת s �е���˳���õ����ո��������ַ�����
˵����
�����ַ��� s ������ǰ�桢������ߵ��ʼ��������Ŀո�
��ת�󵥴ʼ�Ӧ������һ���ո�ָ���
��ת����ַ����в�Ӧ��������Ŀո�
ʾ�� 1��
���룺s = "the sky is blue"
�����"blue is sky the"
ʾ�� 2��
���룺s = "  hello world  "
�����"world hello"
���ͣ������ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
ʾ�� 3��
���룺s = "a good   example"
�����"example good a"
���ͣ�����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
ʾ�� 4��
���룺s = "  Bob    Loves  Alice   "
�����"Alice Loves Bob"
ʾ�� 5��
���룺s = "Alice does not even like bob"
�����"bob like even not does Alice"
��ʾ��
1 <= s.length <= 10^4
s ����Ӣ�Ĵ�Сд��ĸ�����ֺͿո� ' '
s �� ���ٴ���һ�� ����
���ף�
�볢��ʹ�� O(1) ����ռ临�Ӷȵ�ԭ�ؽⷨ��
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = 0, i = 0;
        while (i < s.size())
        {
            while (s[i] != ' ' && i < s.size())
                s[n++] = s[i++];
            if (s[i] == ' ' && n > 0 && s[n - 1] != ' ')
                s[n++] = s[i++];
            else
                i++;
        }
        if (s[n - 1] == ' ')
            s.erase(s.begin() + n - 1, s.end());
        else
            s.erase(s.begin() + n,s.end());
        reverse(s.begin(), s.end());
        
        int a = 0, b = 0;
        i = 0; 
        while (i < s.size())
        {
            if (i == 0 || s[i - 1] == ' ')
                a = i;
            if (i == s.size() - 1 || s[i + 1] == ' ')
            {
                b = i;
                reverse(s.begin() + a, s.begin() + b + 1);
            }
            i++;
        }
        return s;
    }
};

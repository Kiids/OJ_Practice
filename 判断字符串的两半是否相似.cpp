/*
����һ��ż�����ȵ��ַ��� s �������ֳɳ�����ͬ�����룬ǰһ��Ϊ a ����һ��Ϊ b ��
�����ַ��� ���� ��ǰ�������Ƕ�������ͬ��Ŀ��Ԫ����'a'��'e'��'i'��'o'��'u'��'A'��'E'��'I'��'O'��'U'����ע�⣬s ����ͬʱ���д�д��Сд��ĸ��
��� a �� b ���ƣ����� true �����򣬷��� false ��
ʾ�� 1��
���룺s = "book"
�����true
���ͣ�a = "bo" �� b = "ok" ��a ���� 1 ��Ԫ����b Ҳ�� 1 ��Ԫ�������ԣ�a �� b ���ơ�
ʾ�� 2��
���룺s = "textbook"
�����false
���ͣ�a = "text" �� b = "book" ��a ���� 1 ��Ԫ����b ���� 2 ��Ԫ������ˣ�a �� b �����ơ�
ע�⣬Ԫ�� o �� b �г������Σ���Ϊ 2 ����
ʾ�� 3��
���룺s = "MerryChristmas"
�����false
ʾ�� 4��
���룺s = "AbCdEfGh"
�����true
��ʾ��
2 <= s.length <= 1000
s.length ��ż��
s �� ��д��Сд ��ĸ���
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.size() / 2, suma = 0, sumb = 0;
        string a = s.substr(0,half);
        string b = s.substr(half,half);
        for(int i=0;i<a.size();i++)
        {
            if(a.at(i)=='a'||a.at(i)=='e' ||a.at(i)=='i' ||a.at(i)=='o' ||a.at(i)=='u' ||a.at(i)=='A' ||a.at(i)=='E' ||a.at(i)=='I' ||a.at(i)=='O' ||a.at(i)=='U' )
                suma++;
            if(b.at(i)=='a'||b.at(i)=='e' ||b.at(i)=='i' ||b.at(i)=='o' ||b.at(i)=='u' ||b.at(i)=='A' ||b.at(i)=='E' ||b.at(i)=='I' ||b.at(i)=='O' ||b.at(i)=='U' )
                sumb++;
        }
        if (suma == sumb)
            return true;
        return false;
    }
};

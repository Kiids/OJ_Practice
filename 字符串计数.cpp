/*
���ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��
��������:
ÿ�����ݰ���s1������С��100����s2������С��100����len1��С��100000����len2������len1��С��100000��
�������:
����𰸡�
ʾ��1
����
ab ce 1 2
���
56
*/

#include<iostream>
#include<string>
using namespace std;

int sum(string s)  // ��a��ʼ��s���ַ�������
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)  // ���һλ�Ӻ�a������Ŀ������ǰ�漸λ��������һλ������a-z��26��
        ret = ret * 26 + s[i] - 'a';
    return ret;
}

int main()
{
    string s1, s2;
    long len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2)
        cout << (sum(s2) - sum(s1) - 1) % 1000007 << endl;  // ��1��ȥ��һ���ַ���
    return 0;
}

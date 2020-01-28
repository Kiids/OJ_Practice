/* 
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�
���룺
ͨ������ʽ��
һ���ַ�����
�����
����ƥ��Ľ������ȷ���true���������false
��������:
������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
�������:
����ƥ��Ľ������ȷ���true���������false
ʾ��1
����
te?t*.*
txt12.xls
���
false
*/ 

#include <iostream>
#include <string>
using namespace std;

bool IsMatching(const char* p1, const char* p2)
{
    if (*p1 == '\0' && *p2 == '\0')
        return true;
    if (*p1 == '*' && *(p1+1) == '\0' && *p2 == '\0')
        return true;
    if (*p1 == '\0' || *p2 == '\0')
        return false;
    
    if (*p1 == '?')
        return IsMatching(p1+1, p2+1);
    else if (*p1 == '*')
        return IsMatching(p1+1, p2) || IsMatching(p1+1, p2+1) || IsMatching(p1, p2+1);
    else if (*p1 == *p2)
        return IsMatching(p1+1, p2+1);
    else
        return false;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int ret = IsMatching(s1.c_str(), s2.c_str());
        if (ret == 1)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}


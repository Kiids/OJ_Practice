/*
NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�
��������:
��������������ݡ�
ÿ�����ݵĵ�һ����һ������n (1��n��128)����ʾ������n��������
������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
�������:
��Ӧÿһ�����룬���һ���ռ����б�
ʾ��1
����
3<br/>Joe<br/>Quan, William<br/>Letendre,Bruce<br/>2<br/>Leon<br/>Kewell
���
Joe, "Quan, William", "Letendre,Bruce"<br/>Leon, Kewell
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0;
    string s = "";
    while (cin >> n)
    {
        int flag = 0;
        string str = "";
        getline(cin, s);
        while (n--)
        {
            flag = 0;
            getline(cin, s);
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ' || s[i] == ',')
                    flag = 1;
            }
            if (flag == 1)
            {
                str = str + '"' + s + '"';
                if (n >= 1)
                    str = str + ", ";
            }
            else
            {
                str = str + s;
                if (n >= 1)
                    str = str + ", ";
            }
        }
        cout << str << endl;
        str.clear();
    }
    return 0;
}

/* 
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
��������:
���������ַ���
�������:
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop
*/ 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s1.size() < s2.size())
            swap(s1, s2);
        string ret = "";
        for (int i = 0; i < s2.size(); i++)
        {
            for (int j = 0; j < s1.size(); j++)
            {
                string t = s2.substr(i, j);  // substr�������ַ���,ָ��λ�ÿ�ʼ,ָ���ĳ���;���û��ָ�����Ȼ򳬳�Դ�ַ�������,�����ַ�����������Դ�ַ����Ľ�β 
                if ((int)s1.find(t) < 0)
                    break;
                else if (ret.size() < t.size())
                    ret = t;
            }
        }
        cout << ret << endl;
    }
    return 0;
}


/*
����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺʹ�������Ļ���������Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�����˵�����ɿո񡢾�źͶ��Ÿ�����
��������:
�����������У��ܼƲ�����1000���ַ���
�������:
�����ʽ�μ�������
ʾ��1
����
A blockhouse is a small castle that has four openings through which to shoot.
���
a:2
blockhouse:1
castle:1
four:1
has:1
is:1
openings:1
shoot:1
small:1
that:1
through:1
to:1
which:1
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
 
void Print(map<string, int> m)
{
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << ':' << i->second << endl;
}

int main()
{
    string s, p;
    map<string,int> a;
    getline(cin,s);
    int mark = 0;
    auto i = s.begin();
    for (; i != s.end(); i++)
    {
        while(*i == ',' || *i == ' ' || *i == '.')
        {
            if (s.begin() != i)
            {
                p.assign(s.begin(), i);  // assign() ����Ҫô������[start, end)��Ԫ�ظ�����ǰvector,���߸�num��ֵΪval��Ԫ�ص�vector��.����������������Ϊvector��ֵ��ǰ������
                if (p[0] >= 'A' && p[0] <= 'Z')
                    p[0]+=32;
                a[p]++;
            }
            s.erase(s.begin(), i + 1);
            i = s.begin();
            if (s.begin() == s.end())
            {
                mark = 1;
                Print(a);
                break;
            }
        }
        if (mark == 1)
            break;
    }
    return 0;
}


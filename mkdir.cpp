/*
�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin��������Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����
��������:
��������������ݡ�
ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)��
������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ���
�������:
��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir -p�����
ÿ������֮�����һ��������Ϊ�ָ���
ʾ��1
����
3<br/>/a<br/>/a/b<br/>/a/b/c<br/>3<br/>/usr/local/bin<br/>/usr/bin<br/>/usr/local/share/bin
���
mkdir -p /a/b/c<br/><br/>mkdir -p /usr/bin<br/>mkdir -p /usr/local/bin<br/>mkdir -p /usr/local/share/bin
*/

// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isZiChuan(string s1, string s2)
{
    if (s1[1] == s2[1])
    {
        s2 = s2.substr(0, s1.size());  // ��s2�ض�����s1һ����
        if (s1 == s2)  // �����������s1��s2���Ӵ�
            return true;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        
        string str = "mkdir -p ";
        for (int i = 0; i < v.size() - 1; )
        {
            if (isZiChuan(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')  // ǰ���Ǻ��ߵ��Ӵ������Һ��ߵ���һ��λ����/����˵��ǰ�߱������ں�����
                v.erase(v.begin() + i);
            else
                i++;
        }
        for (auto s : v)
            cout << str << s << endl;
        
        cout << endl;
    }
    return 0;
}

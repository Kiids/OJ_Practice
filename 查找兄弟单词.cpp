/*
��������:
�������ֵ��е��ʵĸ�����������n��������Ϊ�ֵ䵥�ʡ�
����һ�����ʣ����������ֵ����ֵܵ��ʵĸ���
����������n
�������:
�������룬������ҵ����ֵܵ��ʵĸ���
ʾ��1
����
3 abc bca cab abc 1
���
2
bca
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isBrother(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        if (s1 == s2)
            return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        if (s1 == s2)
            return true;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        
        string str;
        cin >> str;
        int n;
        cin >> n;  // ���ҵ���n���ֵܵ���
        int sum = 0;
        string s2;
        for (int i = 0; i < v.size(); i++)
        {
            if (isBrother(str, v[i]))
            {
                sum++;
                if (sum == n)
                    s2 = v[i];
            }
        }
        cout << sum << endl;
        if (sum >= n)  // ������ҵ��ĵ�n���ֵܵ��ʣ�ȷ����n������
            cout << s2 << endl;
    }
    return 0;
}

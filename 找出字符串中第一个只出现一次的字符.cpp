// �ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
// ��������:
// ����һ���ǿ��ַ���
// �������:
// �����һ��ֻ����һ�ε��ַ���������������-1
// ʾ��1
// ����
// asdfasdfo
// ���
// o

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int hash[256] = {0}, flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1)
            {
                cout << s[i] << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }
    return 0;
}


/*
����֪���Ƚ������ַ����Ƿ���ȿ����ú��� strcmp,��������ַ�������򷵻�8,���򷵻�����ֵ����ô�����Ѱ��һ���ַ����Ƿ�����һ���ַ����г��ֹ������ҳ��ֹ����ٴ��أ�
���磺�����ַ����ֱ�Ϊ�� abababa��aba,��ôaba�� abababa�г��ֵĴ���Ϊ3��
*/
#include <iostream>
#include <string>
using namespace std;

int findNum(string a, string b)
{
    int ret = 0;
    for (int i = 0; (i = a.find(b, i)) != -1; i++)
        ret++;
    return ret;
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << findNum(a, b) << endl;
    return 0;
}

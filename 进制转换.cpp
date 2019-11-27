// ����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������ 
// ��������:
// ����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
// �������:
// Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
// ʾ��1
// ����
// 7 2
// ���
// 111

#include <iostream>
#include <string>
using namespace std;

string TenToN(int m, int n)
{
    string ret = "";
    string map = "0123456789ABCDEF";
    int flag = 0;
    if (m == 0)
        return 0;
    if (m < 0)
    {
        m = -m;
        flag = 1;
    }
    while (m)
    {
        ret = map[m%n] + ret;
        m = m/n;
    }
    if (flag == 1)
        ret = '-' + ret;
    return ret;
}

int main()
{
    int M, N;
    while(cin >> M >> N)
        cout << TenToN(M, N) << endl;
    return 0;
}

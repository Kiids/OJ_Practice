/*
������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
��������:
��������������A��B��
�������:
���A��B����С��������
ʾ��1
����
5 7
���
35
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B, n;
    cin >> A >> B;
    int max = A>B ? A : B;
    for (n = max; n <= A*B; n++)
    {
        if (n%A == 0 && n%B == 0)
            break;
    }
    cout << n << endl;
    return 0;
}
/*
��ʵ�����½ӿ�
     public   static   int  findNumberOf1( int num)
    {
         /*  ��ʵ��  *//*
         return  0;
    } Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
�漰֪ʶ�㣺
��������:
����һ������
�������:
����������������1�ĸ���
ʾ��1
����
5
���
2
*/

#include <iostream>
using namespace std;

int findNumberOf1(int num)
{
    int n = 0;
    for (int i = 0; i < 32; i++)
    {
        if (num & 1 == 1)
            n++;
        num >>= 1;
    }
    return n;
}

int main()
{
    int x, n = 0;
    while (cin >> x)
    {
        cout << findNumberOf1(x) << endl;
    }
    return 0;
}


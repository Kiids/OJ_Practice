/*
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣� 
    /**
     * ͳ�Ƴ�����������
     * 
     * @param monthCount �ڼ�����
     * @return ��������
     *//*
    public static int getTotalCount(int monthCount)
    {
        return 0;
    }
��������:
����int�ͱ�ʾmonth
�������:
�����������int��
ʾ��1
����
9
���
34
*/

#include <iostream>
using namespace std;

int Sum(int mouth)
{
    int sum = 0;
    if (mouth == 1 || mouth == 2)
        sum = 1;
    else if (mouth == 3)
        sum = 2;
    else
        sum = Sum(mouth - 1) + Sum(mouth - 2);
    return sum;
}

int main()
{
    int m, sum = 0;
    while (cin >> m)
        cout << Sum(m) << endl;
    return 0;
}


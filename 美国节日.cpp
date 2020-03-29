/*
���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
* 1��1�գ�Ԫ��
* 1�µĵ���������һ������·�¡��������
* 2�µĵ���������һ����ͳ��
* 5�µ����һ������һ��������ʿ������
* 7��4�գ���������
* 9�µĵ�һ������һ���Ͷ���
* 11�µĵ��ĸ������ģ��ж���
* 12��25�գ�ʥ����
���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
��������:
��������������ݣ�ÿ�����ݰ���һ��������year��2000��year��9999����
�������:
��Ӧÿһ�����ݣ��ԡ�YYYY-MM-DD����ʽ����������еĽ������ڣ�ÿ������ռһ�С�
ÿ������֮�����һ��������Ϊ�ָ���
ʾ��1
����
2014<br/>2013
���
2014-01-01<br/>2014-01-20<br/>2014-02-17<br/>2014-05-26<br/>2014-07-04<br/>2014-09-01<br/>2014-11-27<br/>2014-12-25<br/><br/>2013-01-01<br/>2013-01-21<br/>2013-02-18<br/>2013-05-27<br/>2013-07-04<br/>2013-09-02<br/>2013-11-28<br/>2013-12-25
*/

#include<iostream>
using namespace std;

int GetDate(int year, int month, int num, int week, int reverse)
{
    int day = 0, weekday = 0, i = 0;
    if (month == 1)
    {
        month = 13;
        year -= 1;
    }
    if (month == 2)
    {
        month = 14;
        year -= 1;
    }
    
    for (day = reverse ? 1 : 31; day <= reverse ? 31 : 1; reverse ? (day++) : (day--))
    {
        weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        if (weekday + 1 == week)
            i++;
        if (i == num)
            break;
    }
    
    return day;
}

int main()
{
    int y = 0;
    while (cin >> y)
    {
        printf("%d-01-01\n", y);
        printf("%d-01-%02d\n", y, GetDate(y, 1, 3, 1, 1));
        printf("%d-02-%02d\n", y, GetDate(y, 2, 3, 1, 1));
        printf("%d-05-%02d\n", y, GetDate(y, 5, 1, 1, 0));
        printf("%d-07-04\n", y);
        printf("%d-09-%02d\n", y, GetDate(y, 9, 1, 1, 1));
        printf("%d-11-%02d\n", y, GetDate(y, 11, 4, 4, 1));
        printf("%d-12-25\n", y);
        cout << endl;
    }
    return 0;
}


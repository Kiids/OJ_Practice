/*
NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
���ڸ���һ��ʱ�����䣬������������������ж��١�
��������:
��������������ݡ�
ÿ�����ݰ�����������from��to (2000-01-01 �� from �� to �� 2999-12-31)��
������������������ʾ���ÿո������year month day��
�������:
��Ӧÿһ�����ݣ�����ڸ��������ڷ�Χ��������ʼ�ͽ������ڣ�����׬����Ǯ��
ʾ��1
����
2000 1 1 2000 1 31<br/>2000 2 1 2000 2 29
���
62<br/>29
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int year1, month1, day1, year2, month2, day2;
    int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int sum = 0;
        int year = year1;
        
        for (int i = year1; i <= year2 - 1; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                sum += 580;
            else
                sum += 579;
        }
 
        for (int i = 0; i <= month1 - 1; i++)
        {
            int t = 0;
            if (i == month1 - 1) 
                t = day1 - 1;
            else 
                t = d[i];
            if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
                sum -= t * 2;
            else 
                sum -= t;
        }
        
        for (int i = 0; i <= month2 - 1; i++)
        {
            int t = 0;
            if (i == month2 - 1)
                t = day2;
            else 
                t = d[i];
            if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
                sum += t * 2;
            else 
                sum += t;
        }
        
        cout << sum << endl;
    }
    return 0;
}


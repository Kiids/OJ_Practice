/*
和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。
输入描述:
输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
输出描述:
对应每一组数据，以“YYYY-MM-DD”格式输出当年所有的节日日期，每个日期占一行。
每组数据之后输出一个空行作为分隔。
示例1
输入
2014<br/>2013
输出
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


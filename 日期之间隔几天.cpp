/*
请你编写一个程序来计算两个日期之间隔了多少天。
日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。
示例 1：
输入：date1 = "2019-06-29", date2 = "2019-06-30"
输出：1
示例 2：
输入：date1 = "2020-01-15", date2 = "2019-12-31"
输出：15
提示：
给定的日期是 1971 年到 2100 年之间的有效日期。
*/

class Solution {
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool IsLeep(int year)
    {
        return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));
    }

    int Date2day(string date)
    {
        stringstream ss(date);
        int year = 0, month = 0, day = 0;
        string curr;
        while (std::getline(ss, curr, '-'))
        {
            if (year == 0)
                year = stoi(curr);
            else if (month == 0)
                month = stoi(curr);
            else
                day = stoi(curr);
        }
        int ret = day;
        while (month > 0)
        {
            month--;
            ret += months[month];
            
            if (month == 2 &&  IsLeep(year))
                ret++;
        }
        ret += 365 * (year - 1 - 1970);
        // 考虑额外闰月的补偿
        // 加上所有模 4 为 0 的年份的数量。此时有些模 100 为 0 的不是闰年的年份被加上了
        // 加上所有模 400 为 0 的年份的数量
        // 减去所有模 100 为 0 的年份的数量。此时有些模 400 为 0 的是闰年的年份被减去了
        ret += (year - 1) / 400 - 4;   // 1970 / 400 = 4
        ret += (year - 1) / 4 - 492;   // 1970 / 4 = 492
        ret -= (year - 1) / 100 - 19;  // 1970 / 100 = 19
        return ret;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(Date2day(date1) - Date2day(date2));
    }
};

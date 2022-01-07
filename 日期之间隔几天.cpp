/*
�����дһ��������������������֮����˶����졣
�������ַ�����ʽ��������ʽΪ YYYY-MM-DD����ʾ����ʾ��
ʾ�� 1��
���룺date1 = "2019-06-29", date2 = "2019-06-30"
�����1
ʾ�� 2��
���룺date1 = "2020-01-15", date2 = "2019-12-31"
�����15
��ʾ��
������������ 1971 �굽 2100 ��֮�����Ч���ڡ�
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
        // ���Ƕ������µĲ���
        // ��������ģ 4 Ϊ 0 ����ݵ���������ʱ��Щģ 100 Ϊ 0 �Ĳ����������ݱ�������
        // ��������ģ 400 Ϊ 0 ����ݵ�����
        // ��ȥ����ģ 100 Ϊ 0 ����ݵ���������ʱ��Щģ 400 Ϊ 0 �����������ݱ���ȥ��
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

/*
����һ���ַ��� date �����ĸ�ʽΪ Day Month Year �����У�
Day �Ǽ��� {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} �е�һ��Ԫ�ء�
Month �Ǽ��� {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} �е�һ��Ԫ�ء�
Year �ķ�Χ��  [1900, 2100] ֮�䡣
���㽫�ַ���ת��Ϊ YYYY-MM-DD �ĸ�ʽ�����У�
YYYY ��ʾ 4 λ����ݡ�
MM ��ʾ 2 λ���·ݡ�
DD ��ʾ 2 λ��������
ʾ�� 1��
���룺date = "20th Oct 2052"
�����"2052-10-20"
ʾ�� 2��
���룺date = "6th Jun 1933"
�����"1933-06-06"
ʾ�� 3��
���룺date = "26th May 1960"
�����"1960-05-26"
��ʾ��
�������ڱ�֤�ǺϷ��ģ����Բ���Ҫ�����쳣���롣
*/

class Solution {
public:
    string reformatDate(string date) {
        stringstream s(date);
        string year, month, day;
        s >> day >> month >> year;
        day = isdigit(day[1]) ? day.substr(0,2) : '0' + day.substr(0,1);
        vector<string> v{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 12; i++)
            if (month == v[i]) {
                month = (i < 9) ? '0' + to_string(i+1) : to_string(i+1);
                break;
            }
        return year + '-' + month +'-' + day;
    }
};

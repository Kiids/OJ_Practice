// ������������ڣ���������һ��ĵڼ��졣��
// ��ϸ������
// ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
// �ӿ���Ƽ�˵����
 /*****************************************************************************
 Description   : ����ת��
 Input Param   : year �������
                Month �����·�
                Day ������
                    
 Output Param  :
 Return Value  : �ɹ�����0��ʧ�ܷ���-1���磺���ݴ���
 *****************************************************************************/
// public static int iConverDateToDay(int year, int month, int day)
// {
     /* ������ʵ�ֹ��ܣ��������������������*/ 
//     return 0;
// }
 
 /*****************************************************************************
 Description   : 
 Input Param   :
                    
 Output Param  :
 Return Value  : �ɹ�:����outDay��������ĵڼ���;
                                           ʧ��:����-1
 *****************************************************************************/
// public static int getOutDay()
// {
//  return 0;
// }

#include <iostream>
using namespace std;
    int GetDay(int year, int mouth, int day)
    {
        int days[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int d = days[mouth - 1];
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            if (mouth > 2)
                d++;
        return d + day;
    }
int main()
{
    int year, mouth, day;
    while (cin >> year >> mouth >> day)
    {
        cout << GetDay(year, mouth, day) << endl;
    }
}

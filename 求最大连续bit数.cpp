/*
����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1  
����: һ��byte�͵�����  
���: ��   
����: ��Ӧ�Ķ�����������1�����������
��������:
����һ��byte����
�������:
���ת�ɶ�����֮������1�ĸ���
ʾ��1
����
3
���
2
*/

#include <iostream>
using namespace std;

int main()
{
    int b, n = 0, max = 0;
    while (cin >> b)
    {
        n = 0;
        max = 0;
        while (b)
        {
            if (b%2 == 0)
                n = 0;
            else
                n++;
            if (n > max)
                max = n;
            b /= 2;
        }
        cout << max << endl;
    }
    return 0;
}

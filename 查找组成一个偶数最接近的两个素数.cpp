/*
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
����ĿҪ��������ָ��ż��������������ֵ��С��������
��������:
����һ��ż��
�������:
�����������
ʾ��1
����
20
���
7
13
*/

#include <iostream>
using namespace std;

bool isPrime(int x)
{
	for (int i = 2; i <= x/2; i++)
		if (x % i == 0)
			return false;
	return true;
}
 
int main()
{
    int a;
    while (cin >> a)
    {
        int sub = 0, min = 0, ret = 0;
        for (int i = 2; i <= a/2; i++)
        {
            if (isPrime(i) && isPrime(a - i))
            {
                sub = a - i - i;
                if (min == 0 || min > sub)
                {
                    min = sub;
                    ret = i;
                }
            }
        }
        cout << ret << endl;
        cout << a - ret << endl;
    }

	return 0;
}

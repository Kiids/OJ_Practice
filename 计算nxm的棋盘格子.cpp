/*
���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ� 
��������:
��������������
�������:
���ؽ��
ʾ��1
����
2
2
���
6
*/

#include <iostream>
using namespace std;

int fun(int n, int m)
{
    if (n == 0 && m == 0)
        return 0;
    if (n == 0 || m == 0)
        return 1;
    return fun(n-1, m) + fun(n, m-1);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
        cout << fun(n, m) << endl;
    return 0;
}

// ��̬�滮��ݹ� 

/*
n ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������ǡ������ƻ������һ����ţ�ϣ���������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� -1��
��������:
ÿ���������һ������������ÿ�����������ĵ�һ�а���һ������ n��1 <= n <= 100������������һ�а��� n ������ ai��1 <= ai <= 100����
�������:
���һ�б�ʾ������Ҫ�ƶ����ٴο���ƽ��ƻ���������������������� -1��
ʾ��1
����
4
7 15 9 5
���
3
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    
    if (sum % n != 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    
    int avg = sum / n, ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(v[i] - avg) % 2 != 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        else
        {
            ret += abs(v[i] - avg) / 2;
        }
    }
    cout << ret / 2 << endl;
    return 0;
}

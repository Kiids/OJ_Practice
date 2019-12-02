/*
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3
��������:
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���
�������:
���������������к�����ֵ��
ʾ��1
���� 
3 -1 2 1
���
3
*/

#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, max = -1e5;  // ���Ǹ��������max��Ϊ��С����
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        
        if (sum > max)
            max = sum;
        
        if (sum < 0)
            sum = 0;
    }
    cout << max << endl;
    
    return 0;
}
// ֻҪǰ��������ģ���һ����Ժ����й��ף�ÿ����һ�����ж��ܺ�>0
// ������max�Ǹ����������max��Ҫ��ȫ�Ǹ�����һ����������Ȼ��ֵΪ��һ�������жϵ�ǰ��С��0����һ�����¿�ʼ������
// ������Ϊ���Ǹ������Լ����������ᳬ��max��Ҳ���ǵ�һ��������

// ���� 
/* 
int main()
{
    int n, sum = 0, max = -1e5;  // ����ȫ�Ǹ��������maxȡ��С��
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (sum > max)
            max = sum;
        
        if (sum < 0)
            sum = 0;
    }
    cout << max << endl;
    return 0;
}
*/

// ���� 
// ���г�ʱ:���ĳ���δ���ڹ涨ʱ�������н����������Ƿ�ѭ���д���㷨���Ӷȹ���
// caseͨ����Ϊ90.00% 
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, max = -1e5;  // ���Ǹ��������max��Ϊ��С��
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n-1; i++)
    {
        sum = a[i];
        for (int j = i+1; j < n; j++)
        {
            if (max < sum)
                max = sum;
            sum += a[j];
        }
        if (max < sum)
            max = sum;
    }
    cout << max << endl;
    
    return 0;
}

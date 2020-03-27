/*
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
�������:
���һ�б�ʾ���ĳ˻���
ʾ��1
����
3
7 4 7
2 50
���
49
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        int k, d;
        cin >> k >> d;
        
        vector<vector<long long>> vmax(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> vmin(n, vector<long long>(k + 1, 0));
        
        // �Ե�i����Ϊ��β��ѡ��j���˵������С�˻�
        for (int i = 0; i < n; i++)
        {
            vmax[i][1] = v[i];
            vmin[i][1] = v[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j <= k; j++)
            {
                for (int m = max(0, i - d); m <= i - 1; m++)
                {
                    vmax[i][j] = max(vmax[i][j], max(vmax[m][j - 1] * v[i], vmin[m][j - 1] * v[i]));
                    vmin[i][j] = min(vmin[i][j], min(vmin[m][j - 1] * v[i], vmax[m][j - 1] * v[i]));
                }
            }
        }
        long long ret = vmax[k - 1][k];
        for (int i = k; i < n; i++)
            ret = max(ret, vmax[i][k]);
        cout << ret << endl;
    }
    return 0;
}

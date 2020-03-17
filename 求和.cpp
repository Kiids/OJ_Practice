/*
������������ n �� m��������1��2��3.......n ������ȡ������,ʹ��͵��� m ,Ҫ���������еĿ�������г���
��������:
ÿ�������������2������,n��m
�������:
��ÿ����ϵ��ֵ����������,ÿ�����һ�����
ʾ��1
����
5 5
���
1 4<br/>2 3<br/>5
*/

#include<iostream>
#include<vector>
using namespace std;

// �������� 
void fun(int begin, int n, int m, vector<int> v)  // n��1��n������  m�������ռ� 
{
    if (n == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < v.size(); i++)
            if (i == 0)
                cout << v[i];
            else
                cout << " " << v[i];
        cout << endl;
        return;
    }
    if (m < 0 || begin > n)
        return;
    
    // ѡ�� 
    v.push_back(begin);
    fun(begin + 1, n, m - begin, v);
    
    // ��ѡ�� 
    v.pop_back();
    fun(begin + 1, n, m, v);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        fun(1, n, m, v);
    }
    return 0;
}

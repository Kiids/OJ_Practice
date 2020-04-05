/*
Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�
�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�
��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ�����������
������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����
�������:
��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�
ʾ��1
����
6<br/>A connect<br/>A disconnect<br/>B connect<br/>C connect<br/>B disconnect<br/>C disconnect
���
2
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        queue<char> q;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            char id;
            cin >> id;
            string s;
            cin >> s;
            
            if (s == "connect")
                q.push(id);
            else
            {
                sum = q.size() > sum ? q.size() : sum;
                q.pop();
            }
        }
        cout << sum << endl;
    }
    return 0;
}

/*
NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
��������:
�����ж������ݣ�ÿ�����������С�
��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���
�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
�������:
����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!������ʾ����ʼ���Ҫ�����ȴ���
ʾ��1
����
Joe,Kewell,Leon
Joe
"Letendre, Bruce",Joe,"Quan, William"
William
���
Ignore
Important!
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        vector<string> v;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '\"')
            {
                int end = s.find('\"', i + 1);
                v.push_back(s.substr(i + 1, end - i - 1));
                i = end + 2;
            }
            else 
            {
                int end = s.find(",", i + 1);
                if (end == -1)
                {
                    v.push_back(s.substr(i, s.size() - i));
                    break;
                }
                v.push_back(s.substr(i, end - i));
                i = end + 1;
            }
        }
        getline(cin, s);
        if (v.end() == find(v.begin(), v.end(), s))
            cout << "Important!" << endl;
        else
            cout << "Ignore" << endl;
    }
    return 0;
}

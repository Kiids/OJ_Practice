/*
��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT-GLOP�ʹ���888-4567��310-GINO����310-4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�
��������:
��������������ݡ�
ÿ�����ݵ�һ�а���һ��������n��1��n��1024����
������n�У�ÿ�а���һ���绰���룬�绰����������ַ���-�������ֺʹ�д��ĸ��ɡ�
û���������ֵ����ַ��������ų����ַ��󳤶�ʼ��Ϊ7�������绰����ֻ��7λ����
�������:
��Ӧÿһ�����룬�����ֵ�˳��������ظ��ı�׼������ʽ�绰���룬����xxx-xxxx����ʽ��
ÿ���绰����ռһ�У�ÿ������֮�����һ��������Ϊ�������
ʾ��1
����
12<br/>4873279<br/>ITS-EASY<br/>888-4567<br/>3-10-10-10<br/>888-GLOP<br/>TUT-GLOP<br/>967-11-11<br/>310-GINO<br/>F101010<br/>888-1200<br/>-4-8-7-3-2-7-9-<br/>487-3279<br/>4<br/>UTT-HELP<br/>TUT-GLOP<br/>310-GINO<br/>000-1213
���
310-1010<br/>310-4466<br/>487-3279<br/>888-1200<br/>888-4567<br/>967-1111<br/><br/>000-1213<br/>310-4466<br/>888-4357<br/>888-4567
*/

#include<iostream>
#include<string>
#include<set>
using namespace std;

string getNum(string s)
{
    string ret = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            ret += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            switch (s[i])
            {
                case 'A':
                case 'B':
                case 'C':
                    ret += '2';
                    break;
                case 'D':
                case 'E':
                case 'F':
                    ret += '3';
                    break;
                case 'G':
                case 'H':
                case 'I':
                    ret += '4';
                    break;
                case 'J':
                case 'K':
                case 'L':
                    ret += '5';
                    break;
                case 'M':
                case 'N':
                case 'O':
                    ret += '6';
                    break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                    ret += '7';
                    break;
                case 'T':
                case 'U':
                case 'V':
                    ret += '8';
                    break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    ret += '9';
                    break;
            }
        }
        else
            continue;
    }
    string ret1 = ret.substr(0, 3);
    string ret2 = ret.substr(3, 4);
    ret = "";
    ret += ret1;
    ret += '-';
    ret += ret2;
    return ret;
}

int main()
{
    int n;
    while (cin >> n)
    {
        set<string> l;
        for (int i = 0; i < n; i++)
        {
            string s, str;
            cin >> s;
            str = getNum(s);
            l.insert(str);
        }
        for (auto &e : l)
            cout << e << endl;
        cout << endl;
    }
    return 0;
}

// ����һ���ַ���str������ַ���str�е�����������ִ�
// ��������:
// �������������1������������һ���ַ���str�����Ȳ�����255��
// �������:
// ��һ�������str��������������ִ���
// ʾ��1
// ����
// abcd12345ed125ss123456789
// ���
// 123456789

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, ret;
    int max = 0;
    while (getline(cin, s))
    {
    	if (s == "")
    		break;
    	max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string str = "";
            int l = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                str += s[i];
                l++;
                i++;
            }
            if (l > max)
            {
                ret = str;
                max = l;
            }
        }
        
        cout << ret << endl;
    }
    return 0;
}

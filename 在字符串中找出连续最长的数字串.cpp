��������:
����һ���ַ�����
�������:
����ַ�������������ַ��������ĳ��ȡ��������ͬ���ȵĴ�����Ҫһ�����������ǳ��Ȼ���һ���ĳ���
ʾ��1
����
abcd12345ed125ss123058789
���
123058789,9

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        string ret;
        vector<string> a;

        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ret += s[i];
            }
            else
            {
                if (ret.size() != 0)
                {
                    a.push_back(ret);
                }
                ret.clear();
            }
        }

        int max = 0;
        int l = 0;

        for (int i = 0; i < a.size(); i++)
        {
            if (max < (a[i]).size())
            {
                max = (a[i]).size();
                l = max;
            }
        }

        for (int i = 0; i < a.size(); i++)
        {
            if (max == (a[i]).size())
            {
                cout << a[i];
            }
        }
        cout << "," << l << endl;
    }
    return 0;
}

/*
�������
���123058789����������ֵ9
���54761����������ֵ5
�ӿ�˵��
����ԭ�ͣ�
   unsignedint Continumax(char** pOutputstr,  char* intputstr)
���������
   char* intputstr  �����ַ�����
���������
   char** pOutputstr: ����������ִ����������������ִ��ĳ���Ϊ0��Ӧ�÷��ؿ��ַ�������������ַ����ǿգ�ҲӦ�÷��ؿ��ַ�����  
����ֵ��
  ����������ִ��ĳ���
*/
// ���´��벢����ʵ���������� 
/*#include <iostream>
#include <cstring>
using namespace std;

unsigned int Continumax(char** pOutputstr,  char* intputstr)
{
    if (intputstr == "")
    {
        *pOutputstr = "";
        return 0;
    }
    
    unsigned int max = 0;
    for (int i = 0; i < strlen(intputstr); i++)
    {
        char* str = "";
        int l = 0;
        while (intputstr[i] >= '0' && intputstr[i] <= '9')
        {
            str[i] = intputstr[i];
            l++;
            i++;
        }
        if (l > max)
        {
            *pOutputstr = str;
            max = l;
        }
    }
    return max;
}

int main()
{
    char *s, *ret;
    cin >> s;
    unsigned int n = Continumax(&ret, s);
    cout << ret << "," << n << endl;
    return 0;
}*/

输入描述:
输入一个字符串。
输出描述:
输出字符串中最长的数字字符串和它的长度。如果有相同长度的串，则要一块儿输出，但是长度还是一串的长度
示例1
输入
abcd12345ed125ss123058789
输出
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
样例输出
输出123058789，函数返回值9
输出54761，函数返回值5
接口说明
函数原型：
   unsignedint Continumax(char** pOutputstr,  char* intputstr)
输入参数：
   char* intputstr  输入字符串；
输出参数：
   char** pOutputstr: 连续最长的数字串，如果连续最长的数字串的长度为0，应该返回空字符串；如果输入字符串是空，也应该返回空字符串；  
返回值：
  连续最长的数字串的长度
*/
// 以下代码并不能实现问题所述 
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

/* 
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop
*/ 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s1.size() < s2.size())
            swap(s1, s2);
        string ret = "";
        for (int i = 0; i < s2.size(); i++)
        {
            for (int j = 0; j < s1.size(); j++)
            {
                string t = s2.substr(i, j);  // substr复制子字符串,指定位置开始,指定的长度;如果没有指定长度或超出源字符串长度,则子字符串将延续到源字符串的结尾 
                if ((int)s1.find(t) < 0)
                    break;
                else if (ret.size() < t.size())
                    ret = t;
            }
        }
        cout << ret << endl;
    }
    return 0;
}


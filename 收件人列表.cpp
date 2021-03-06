/*
NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
输入描述:
输入包含多组数据。
每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。
紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
输出描述:
对应每一组输入，输出一行收件人列表。
示例1
输入
3<br/>Joe<br/>Quan, William<br/>Letendre,Bruce<br/>2<br/>Leon<br/>Kewell
输出
Joe, "Quan, William", "Letendre,Bruce"<br/>Leon, Kewell
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0;
    string s = "";
    while (cin >> n)
    {
        int flag = 0;
        string str = "";
        getline(cin, s);
        while (n--)
        {
            flag = 0;
            getline(cin, s);
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ' || s[i] == ',')
                    flag = 1;
            }
            if (flag == 1)
            {
                str = str + '"' + s + '"';
                if (n >= 1)
                    str = str + ", ";
            }
            else
            {
                str = str + s;
                if (n >= 1)
                    str = str + ", ";
            }
        }
        cout << str << endl;
        str.clear();
    }
    return 0;
}

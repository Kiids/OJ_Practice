/*
输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和次数在屏幕上输出来，要求能识别英文句号和逗号，即是说单词由空格、句号和逗号隔开。
输入描述:
输入有若干行，总计不超过1000个字符。
输出描述:
输出格式参见样例。
示例1
输入
A blockhouse is a small castle that has four openings through which to shoot.
输出
a:2
blockhouse:1
castle:1
four:1
has:1
is:1
openings:1
shoot:1
small:1
that:1
through:1
to:1
which:1
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
 
void Print(map<string, int> m)
{
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << ':' << i->second << endl;
}

int main()
{
    string s, p;
    map<string,int> a;
    getline(cin,s);
    int mark = 0;
    auto i = s.begin();
    for (; i != s.end(); i++)
    {
        while(*i == ',' || *i == ' ' || *i == '.')
        {
            if (s.begin() != i)
            {
                p.assign(s.begin(), i);  // assign() 函数要么将区间[start, end)的元素赋到当前vector,或者赋num个值为val的元素到vector中.这个函数将会清除掉为vector赋值以前的内容
                if (p[0] >= 'A' && p[0] <= 'Z')
                    p[0]+=32;
                a[p]++;
            }
            s.erase(s.begin(), i + 1);
            i = s.begin();
            if (s.begin() == s.end())
            {
                mark = 1;
                Print(a);
                break;
            }
        }
        if (mark == 1)
            break;
    }
    return 0;
}


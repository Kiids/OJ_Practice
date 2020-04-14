/*
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。
输入描述:
输入包含多组数据。
每组数据第一行为一个正整数n(1≤n≤1024)。
紧接着n行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过200个字符。
输出描述:
对应每一组数据，输出相应的、按照字典顺序排序的“mkdir -p”命令。
每组数据之后输出一个空行作为分隔。
示例1
输入
3<br/>/a<br/>/a/b<br/>/a/b/c<br/>3<br/>/usr/local/bin<br/>/usr/bin<br/>/usr/local/share/bin
输出
mkdir -p /a/b/c<br/><br/>mkdir -p /usr/bin<br/>mkdir -p /usr/local/bin<br/>mkdir -p /usr/local/share/bin
*/

// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isZiChuan(string s1, string s2)
{
    if (s1[1] == s2[1])
    {
        s2 = s2.substr(0, s1.size());  // 将s2截断至和s1一样长
        if (s1 == s2)  // 若两者相等则s1是s2的子串
            return true;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        
        string str = "mkdir -p ";
        for (int i = 0; i < v.size() - 1; )
        {
            if (isZiChuan(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')  // 前者是后者的子串，并且后者的下一个位置是/，则说明前者被包含在后者内
                v.erase(v.begin() + i);
            else
                i++;
        }
        for (auto s : v)
            cout << str << s << endl;
        
        cout << endl;
    }
    return 0;
}

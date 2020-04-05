/*
Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。
现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。
输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。
紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。
输出描述:
对应每一组数据，输出连接池最多需要创建多少个连接。
示例1
输入
6<br/>A connect<br/>A disconnect<br/>B connect<br/>C connect<br/>B disconnect<br/>C disconnect
输出
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

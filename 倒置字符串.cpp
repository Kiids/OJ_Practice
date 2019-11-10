/* 
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I 
输入描述: 
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
示例1
输入
I like beijing.
输出
beijing. like I
*/
 
#if 0 
#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int begin, int end)
{
    char t;
    while (begin < end)
    {
        t = s[begin];
        s[begin] = s[end];
        s[end] = t;
        begin++;
        end--;
    }
}

int main()
{
    string s;
    getline(cin, s);
    
    // 先整个字符串翻转，再对空格间单词翻转
    reverse(s, 0, s.size()-1);
    cout << s << endl;
	 
	int i = 0, j = 0;
    while (i < s.size())
    {
        for (j = i+1; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                reverse(s, i, j-1);
            	break;
			}
        }
        i = j+1;
    }
    cout << s << endl;
    return 0;
}
#endif
 
#if 0
// 思路2：用栈的后进先出的思想
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	stack<string> sstack;
	string line, word;
	getline(cin, line);
	istringstream stream(line);  // <sstream>
	while (stream >> word) {
		sstack.push(word);
	}
	while (!sstack.empty()) {
		cout << sstack.top() << " ";
		sstack.pop();
	}
	return 0;
}
// C++引入了ostringstream、istringstream、stringstream这三个类，使用他们创建对象须包含<sstream>头文件
// istringstream类用于执行C++风格的串流的输入操作
// ostringstream类用于执行C风格的串流的输出操作
// strstream类同时可以支持C风格的串流的输入输出操作
// istringstream的构造函数原形如下：
// istringstream::istringstream(string str);它的作用是从string对象str中读取字符
#endif

#if 1
// 思路三 巧用cin 牛客OJ可以过但是VS2013输出时会触发异常 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, ret = ""; 
	while (cin >> s) 
	{ 
		ret = s + " " + ret;
	}
	cout << ret << endl; 
	return 0; 
}
#endif

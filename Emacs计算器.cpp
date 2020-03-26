/*
Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
输入描述:
输入包含多组数据。
每组数据包括两行：第一行是一个正整数n (3≤n≤50)；紧接着第二行包含n个由数值和运算符组成的列表。
“+ - * /”分别为加减乘除四则运算，其中除法为整除，即“5/3=1”。
输出描述:
对应每一组数据，输出它们的运算结果。
示例1
输入
3<br/>2 3 +<br/>5<br/>2 2 + 3 *<br/>5<br/>2 2 3 + *
输出
5<br/>12<br/>10
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    int n;
    string s;
    while (cin >> n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
            {
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                switch (s[0])
                {
                    case '+':
                        st.push(l + r);
                        break;
                    case '-':
                        st.push(l - r);
                        break;
                    case '*':
                        st.push(l * r);
                        break;
                    case '/':
                        st.push(l / r);
                        break;
                }
            }
            else
            {
                int a = stoi(s);
                st.push(a);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}

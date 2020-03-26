/*
Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������
��������:
��������������ݡ�
ÿ�����ݰ������У���һ����һ��������n (3��n��50)�������ŵڶ��а���n������ֵ���������ɵ��б�
��+ - * /���ֱ�Ϊ�Ӽ��˳��������㣬���г���Ϊ����������5/3=1����
�������:
��Ӧÿһ�����ݣ�������ǵ���������
ʾ��1
����
3<br/>2 3 +<br/>5<br/>2 2 + 3 *<br/>5<br/>2 2 3 + *
���
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

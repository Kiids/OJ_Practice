/*
���ַ����е����е��ʽ��е��š�
˵����
1��ÿ����������26����д��СдӢ����ĸ���ɣ�
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��
��������:
����һ���Կո����ָ��ľ���
�������:
������ӵ�����
ʾ��1
����
I am a student
���
student a am I
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        string str = "";
        stack<string> st;
        int flag = 0; // ȥ����һ������ǰ��Ŀո�
        for (int i = 0; i <= s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                str += s[i];
                flag = 1;
            }
            else
            {
                if (flag == 1)
                {
                    st.push(str);
                    str = "";
                    flag = 0;
                }
            }
        }
        while (st.size() > 1)
        {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

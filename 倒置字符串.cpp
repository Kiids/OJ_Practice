/* 
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I 
��������: 
ÿ�������������1������������ I like beijing. �����������Ȳ�����100
�������:
�����������֮����ַ���,�Կո�ָ�
ʾ��1
����
I like beijing.
���
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
    
    // �������ַ�����ת���ٶԿո�䵥�ʷ�ת
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
// ˼·2����ջ�ĺ���ȳ���˼��
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
// C++������ostringstream��istringstream��stringstream�������࣬ʹ�����Ǵ������������<sstream>ͷ�ļ�
// istringstream������ִ��C++���Ĵ������������
// ostringstream������ִ��C���Ĵ������������
// strstream��ͬʱ����֧��C���Ĵ����������������
// istringstream�Ĺ��캯��ԭ�����£�
// istringstream::istringstream(string str);���������Ǵ�string����str�ж�ȡ�ַ�
#endif

#if 1
// ˼·�� ����cin ţ��OJ���Թ�����VS2013���ʱ�ᴥ���쳣 
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

/*�������������������
xcopy /s c:\ d:\��
�����������£� 
����1��������xcopy 
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\
���дһ��������������ʵ�ֽ������и�����������������
�������� 
1.�����ָ���Ϊ�ո� 
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.���������� 
4.������������֤��������ֲ�����Ҫ������� 
��������:
����һ���ַ����������пո�
�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��
ʾ��1
����
xcopy /s c:\\ d:\\
���
4
xcopy
/s
c:\\
d:\\
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int flag = 0;
		vector<string> v;
		string str;
		for (int i = 0; i < s.size(); i++) 
		{
			if (flag) 
			{
				if (s[i] != '\"')  // ת���ʾ"�ַ�  
					str += s[i];
				else 
					flag = 0;
			}
			else
			{
				if (s[i] == ' ') 
				{
					v.push_back(str);
					str = "";
				} 
				else if (str[i] == '\"') 
					flag = 1;
				else
					str += s[i];
			}
		}
		v.push_back(str);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) 
		cout << v[i] << endl;
	}
	return 0;
}

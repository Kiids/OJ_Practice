/*
��Ŀ���⣺
���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд
��ϸ������
�ӿ�˵��
ԭ�ͣ�
int getCommonStrLength(char * pFirstStr, char * pSecondStr);
���������
     char * pFirstStr //��һ���ַ���

     char * pSecondStr//�ڶ����ַ���
��������:
���������ַ���
�������:
���һ������
ʾ��1
����
asdfas werasdfaswer
���
6
*/

#include <iostream>
#include <string>
using namespace std;

int StrStr(string s1, string s2)
{
	int n = 0, max = 0, k = 0, l = 0;
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
		{
			n = 0;
			k = i;
			l = j;
			while (s1[k] == s2[l] && k < s1.size() && l < s2.size())
			{
				k++;
				l++;
				n++;
			}
			if (n > max)
				max = n; 
		}
	return max;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		for (int i = 0; i < s1.size(); i++)
			s1[i] = tolower(s1[i]);
			
		for (int i = 0; i < s2.size(); i++)
			s2[i] = tolower(s2[i]);
			
		cout << StrStr(s1, s2) << endl;
	}
} 

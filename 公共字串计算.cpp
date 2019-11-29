/*
题目标题：
计算两个字符串的最大公共字串的长度，字符不区分大小写
详细描述：
接口说明
原型：
int getCommonStrLength(char * pFirstStr, char * pSecondStr);
输入参数：
     char * pFirstStr //第一个字符串

     char * pSecondStr//第二个字符串
输入描述:
输入两个字符串
输出描述:
输出一个整数
示例1
输入
asdfas werasdfaswer
输出
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

/*
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
       һ�����볤��:
       5 ��: С�ڵ���4 ���ַ�
       10 ��: 5 ��7 �ַ�
       25 ��: ���ڵ���8 ���ַ�
       ������ĸ:
       0 ��: û����ĸ
       10 ��: ȫ����С����д��ĸ
       20 ��: ��Сд�����ĸ
       ��������:
       0 ��: û������
       10 ��: 1 ������
       20 ��: ����1 ������
       �ġ�����:
       0 ��: û�з���
       10 ��: 1 ������
       25 ��: ����1 ������
       �塢����:
       2 ��: ��ĸ������
       3 ��: ��ĸ�����ֺͷ���
       5 ��: ��Сд��ĸ�����ֺͷ���
       �������ֱ�׼:
       >= 90: �ǳ���ȫ
       >= 80: ��ȫ��Secure��
       >= 70: �ǳ�ǿ
       >= 60: ǿ��Strong��
       >= 50: һ�㣨Average��
       >= 25: ����Weak��
       >= 0:  �ǳ���
��Ӧ���Ϊ��
  VERY_WEAK,
   WEAK,    
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       ���������������ַ��������а�ȫ������
       ע��
       ��ĸ��a-z, A-Z
       ���֣�-9
       ���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
       !"#$%&'()*+,-./     (ASCII�룺x21~0x2F)
       :;<=>?@             (ASCII<=><=><=><=><=>�룺x3A~0x40)
       [\]^_`              (ASCII�룺x5B~0x60)
  {|}~                (ASCII�룺x7B~0x7E)
�ӿ�������

 Input Param 
      String pPasswordStr:    ���룬���ַ�����ʽ��š�
 Return Value
   ���ݹ��������İ�ȫ�ȼ��� 
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
 {
     /*������ʵ�ֹ���*//*
  return null;
 }
��������:
����һ��string������
�������:
�������ȼ�
ʾ��1
����
38$@NoNoNo
���
VERY_SECURE
*/

#include <iostream> 
#include <string> 
using namespace std; 
int getAa(string s)
{     
	int small = 0, big = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			big++;
		else if (s[i] >= 'a' && s[i] <= 'z')
			small++;
	}
	
	if ((small + big) == 0)
		return 0;
	else if (small == s.size() || big == s.size())
		return 10;
	else if (small > 0 && big > 0)
		return 20;
    return 0; 
} 

int getNum(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			num++;
			
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 20;
} 

int getSymbal(string s)
{
	int n = 0;
	for (int i = 0; i < s.size(); i++)
		if (!(s[i] >= 65 && s[i] <= 90) && 
		    !(s[i] >= 97 && s[i] <= 122) && 
		    !(s[i] >= '0' && s[i] <= '9'))
			n++;
			
	if (n == 0)
		return 0;
	else if (n == 1)
		return 10;
	else
		return 25;
}

int main()
{    
	string s;
	while (cin >> s)
	{
		int sum = 0, len = s.size();        
		if (len <= 4)
			sum += 5;
		else if (len >= 8)
			sum += 25;
		else
			sum += 10;
		
		sum += getAa(s) + getNum(s) + getSymbal(s);
		
		if ((getAa(s) > 0) && (getNum(s) > 0) && (getSymbal(s) == 0))
			sum += 2;
		else if ((getAa(s) == 10) && (getNum(s) > 0) && (getSymbal(s) > 0))
			sum += 3;
		else if ((getAa(s) == 20) && (getNum(s) > 0) && (getSymbal(s) > 0))
			sum += 5;
			
		if (sum >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum >= 80 && sum < 90)
			cout << "SECURE" << endl;
		else if (sum >= 70 && sum < 80)
			cout << "VERY_STRONG" << endl;
		else if (sum >= 60 && sum < 70)
			cout << "STRONG" << endl;
		else if (sum >= 50 && sum < 60)
			cout << "AVERAGE" << endl;
		else if (sum >= 25 && sum < 50)
			cout << "WEAK" << endl;
		else if (sum >= 0 && sum < 25)
			cout << "VERY_WEAK" << endl;
	}    
	return 0; 
}

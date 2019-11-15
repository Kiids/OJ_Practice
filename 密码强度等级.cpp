/*
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
       一、密码长度:
       5 分: 小于等于4 个字符
       10 分: 5 到7 字符
       25 分: 大于等于8 个字符
       二、字母:
       0 分: 没有字母
       10 分: 全都是小（大）写字母
       20 分: 大小写混合字母
       三、数字:
       0 分: 没有数字
       10 分: 1 个数字
       20 分: 大于1 个数字
       四、符号:
       0 分: 没有符号
       10 分: 1 个符号
       25 分: 大于1 个符号
       五、奖励:
       2 分: 字母和数字
       3 分: 字母、数字和符号
       5 分: 大小写字母、数字和符号
       最后的评分标准:
       >= 90: 非常安全
       >= 80: 安全（Secure）
       >= 70: 非常强
       >= 60: 强（Strong）
       >= 50: 一般（Average）
       >= 25: 弱（Weak）
       >= 0:  非常弱
对应输出为：
  VERY_WEAK,
   WEAK,    
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       请根据输入的密码字符串，进行安全评定。
       注：
       字母：a-z, A-Z
       数字：-9
       符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
       !"#$%&'()*+,-./     (ASCII码：x21~0x2F)
       :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)
       [\]^_`              (ASCII码：x5B~0x60)
  {|}~                (ASCII码：x7B~0x7E)
接口描述：

 Input Param 
      String pPasswordStr:    密码，以字符串方式存放。
 Return Value
   根据规则评定的安全等级。 
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
 {
     /*在这里实现功能*//*
  return null;
 }
输入描述:
输入一个string的密码
输出描述:
输出密码等级
示例1
输入
38$@NoNoNo
输出
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

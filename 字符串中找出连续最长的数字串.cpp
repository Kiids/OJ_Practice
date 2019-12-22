// 读入一个字符串str，输出字符串str中的连续最长的数字串
// 输入描述:
// 个测试输入包含1个测试用例，一个字符串str，长度不超过255。
// 输出描述:
// 在一行内输出str中里连续最长的数字串。
// 示例1
// 输入
// abcd12345ed125ss123456789
// 输出
// 123456789

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, ret;
    int max = 0;
    while (getline(cin, s))
    {
    	if (s == "")
    		break;
    	max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string str = "";
            int l = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                str += s[i];
                l++;
                i++;
            }
            if (l > max)
            {
                ret = str;
                max = l;
            }
        }
        
        cout << ret << endl;
    }
    return 0;
}

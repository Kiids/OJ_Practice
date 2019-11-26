/* 
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数. 
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
输入描述:
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
输出描述:
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1
输入
1 -2 3 4
输出
2 1 3
*/
 
#include <iostream>
using namespace std;

int main()
{
    int m, n, o, p, a, b, c, flag = 0;
    cin >> m >> n >> o >> p;
    
    for (int i = 0; i <= 60; i++)
        for (int j = 0; j <= 60; j++)
            for (int k = 0; k <= 60; k++)
            {
                if ((i-j == m) && (j-k == n) && (i+j == o) && (j+k == p))
                {
                    flag |= 1;
                    a = i;
                    b = j;
                    c = k;
                }
                else
                    flag |= 0;
            }
    if (flag == 1)
        cout << a << " " << b << " " << c << endl;
    else
        cout << "No" << endl;
    
    return 0;
}

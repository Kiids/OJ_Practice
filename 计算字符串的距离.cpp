/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
Ex：
字符串A:abcdefg
字符串B: abcdef
通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
请实现如下接口
/*  功能：计算两个字符串的距离
 *  输入： 字符串A和字符串B
 *  输出：无
 *  返回：如果成功计算出字符串的距离，否则返回-1
 *//*
     public   static   int  calStringDistance (String charA, String  charB)
    {
        return  0;
    }  
输入描述:
输入两个字符串
输出描述:
得到计算结果
示例1
输入
abcdefg
abcdef
输出
1
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> v(n+1, vector<int>(m+1));
        
        // 给第一行赋值 
        for (int j = 0; j <= m; j++)
            v[0][j] = j;
        // 给第一列赋值 
        for (int i = 0; i <= n; i++)
            v[i][0] = i;
        
        // 最短编辑距离，动态规划 
        // 若两子串的最后一个字符相等，那它们的最短编辑距离就跟删掉最后一个字符后的最短编辑距离相等 
        // 当末尾字符不相等时，在替换、插入、删除中选择令两个字符串编辑距离最少的，并加上1 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int d1 = v[i-1][j-1];
                int d2 = v[i][j-1] + 1;
                int d3 = v[i-1][j] + 1;
                if (s1[i-1] != s2[j-1])
                    d1 += 1;
                v[i][j] = min(min(d1, d2), d3);
            }
        }
        cout << v[n][m] << endl;
    }
    return 0;
}

// https://blog.csdn.net/c20190413/article/details/75030105
// https://blog.csdn.net/shizheng163/article/details/50988023

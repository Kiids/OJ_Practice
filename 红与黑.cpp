/*
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入描述:
输入包含多组数据。
每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：
1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
输出描述:
对应每组数据，输出总共能够到达多少块黑色的瓷砖。
示例1
输入
9 6<br/>....#.<br/>.....#<br/>......<br/>......<br/>......<br/>......<br/>......<br/>#@...#<br/>.#..#.
输出
45
*/

#include<iostream>
#include<string.h>  // memset
using namespace std;

int sum = 0, m, n;
int a[20][20] = { 0 };
void dfs(int x, int y)
{
    if (a[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)
        return;
    sum++;
    a[x][y] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
     
}

int main()
{
    while(cin >> m >> n)
    {
        int x , y;
        char c;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                if (c == '@')
                {
                    x = i;
                    y = j;
                }
                else
                {
                    if (c == '#')
                        a[i][j] = 1;
                }
            }
        }
        dfs(x, y);
        cout << sum << endl;
        sum = 0;
        memset(a, 0, sizeof(a));  // 初始化
    }
 
    return 0;
}

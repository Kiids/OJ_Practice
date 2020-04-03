/*
NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？
输入描述:
输入包含多组数据。
每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；“.”代表通路。
入口在第一行第二列；出口在最后一行第九列。
从任意一个“.”点都能一步走到上下左右四个方向的“.”点。
输出描述:
对应每组数据，输出从入口到出口最短需要几步。
示例1
输入
#.########<br/>#........#<br/>#........#<br/>#........#<br/>#........#<br/>#........#<br/>#........#<br/>#........#<br/>#........#<br/>########.#<br/>#.########<br/>#........#<br/>########.#<br/>#........#<br/>#.########<br/>#........#<br/>########.#<br/>#........#<br/>#.######.#<br/>########.#
输出
16<br/>30
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char c[10][10];
int a[10][10] = {0};
int b[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int e = x + b[i][0];
        int d = y + b[i][1];
        if (e < 10 && e >= 0 && d < 10 && d >= 0 && c[e][d] != '#')
        {
            if ((a[e][d] == 0) || (a[x][y] + 1) < a[e][d])
            {
                a[e][d] = a[x][y] + 1;
                dfs(e, d);
            }
        }
    }
}

int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        c[0][0] = ch;
        for (int i = 1; i < 10; i++)
            scanf("%c", &c[0][i]);
        getchar();  
        
        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                scanf("%c", &c[i][j]);
            getchar();
        }
        
        dfs(0, 1);
        cout << a[9][8] << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}

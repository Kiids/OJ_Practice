/*
定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 
int maze[5][5] = {
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。
Input
一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
Output
左上角到右下角的最短路径，格式如样例所示。
Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
输出描述:
左上角到右下角的最短路径，格式如样例所示。
示例1
输入
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M;  // 行，列
vector<vector<int>> Maze;  // 迷宫矩阵
vector<vector<int>> Path; // 当前路径，每行即第一维表示坐标点
vector<vector<int>> PathBest;  // 最优路径

void MazeGo(int i, int j)
{
    Maze[i][j] = 1;  // 该点已走
    Path.push_back({i, j});  // 添加该点
    
    if (i == N-1 && j == M-1)  // 判断是否到终点
        if (PathBest.empty() || Path.size() < PathBest.size())
            PathBest = Path;
    
    if (i-1 >= 0 && Maze[i-1][j]  == 0)  // 探索上一格子
        MazeGo(i-1, j);
    if (i+1 < N && Maze[i+1][j]  == 0)  // 探索下一格子
        MazeGo(i+1, j);
    if (j-1 >= 0 && Maze[i][j-1]  == 0)  // 探索左一格子
        MazeGo(i, j-1);
    if (j+1 < M && Maze[i][j+1]  == 0)  // 探索右一格子
        MazeGo(i, j+1);
    
    Maze[i][j] = 0;  // 恢复现场，设置为未走过
    Path.pop_back();
}

int main()
{
    while (cin >> N >> M)
    {
        Maze = vector<vector<int>>(N, vector<int>(M, 0));
        Path.clear();
        PathBest.clear();
        for (auto &e : Maze)
            for (auto &f : e)
                cin >> f;
        MazeGo(0, 0);
        for (auto e : PathBest)
            cout << "(" << e[0] << "," << e[1] << ")" << endl;
    }
    return 0;
}

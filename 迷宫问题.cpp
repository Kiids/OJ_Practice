/*
����һ����ά����N*M������2<=N<=10;2<=M<=10������5 �� 5��������ʾ�� 
int maze[5][5] = {
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
};
����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ�ո��ǿ����ߵ�·��
Input
һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����
Output
���Ͻǵ����½ǵ����·������ʽ��������ʾ��
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
���������������ֱ��ʾ��λ�������������������������Ӧ�����飬���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·�����ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����
�������:
���Ͻǵ����½ǵ����·������ʽ��������ʾ��
ʾ��1
����
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
���
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

int N, M;  // �У���
vector<vector<int>> Maze;  // �Թ�����
vector<vector<int>> Path; // ��ǰ·����ÿ�м���һά��ʾ�����
vector<vector<int>> PathBest;  // ����·��

void MazeGo(int i, int j)
{
    Maze[i][j] = 1;  // �õ�����
    Path.push_back({i, j});  // ��Ӹõ�
    
    if (i == N-1 && j == M-1)  // �ж��Ƿ��յ�
        if (PathBest.empty() || Path.size() < PathBest.size())
            PathBest = Path;
    
    if (i-1 >= 0 && Maze[i-1][j]  == 0)  // ̽����һ����
        MazeGo(i-1, j);
    if (i+1 < N && Maze[i+1][j]  == 0)  // ̽����һ����
        MazeGo(i+1, j);
    if (j-1 >= 0 && Maze[i][j-1]  == 0)  // ̽����һ����
        MazeGo(i, j-1);
    if (j+1 < M && Maze[i][j+1]  == 0)  // ̽����һ����
        MazeGo(i, j+1);
    
    Maze[i][j] = 0;  // �ָ��ֳ�������Ϊδ�߹�
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

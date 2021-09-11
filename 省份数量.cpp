/*
�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
���ؾ����� ʡ�� ��������
ʾ�� 1��
���룺isConnected = [[1,1,0],[1,1,0],[0,0,1]]
�����2
ʾ�� 2��
���룺isConnected = [[1,0,0],[0,1,0],[0,0,1]]
�����3
��ʾ��
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] Ϊ 1 �� 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0, n = isConnected.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                ret++;
                DFS(i, n, visited, isConnected);
            }
        }
        return ret;
    }

    void DFS(int x, int n, vector<int>& visited, vector<vector<int>>& isConnected)
    {
        for (int i = 0; i < n; i++)
        {
            if (isConnected[x][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                DFS(i, n, visited,isConnected);
            }
        }
    }
};

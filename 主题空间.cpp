/*
���Կۻ��ѡ����»���ڳ�������������ռ���������ɣ����صĵ�ͼ������һά�ַ��������� grid���ַ����н����� "0"��"5" �� 6 ���ַ�����ͼ��ÿһ���ַ��������Ϊ 1 ���������� "0" ��ʾ���ȣ������ַ���ʾ����ռ䡣��ͬ������������ָ�ϡ��¡������ĸ��������ӣ����ַ����ͬһ������ռ䡣
�������� grid ���������Ϊ���ȡ����ʣ���������ֱ�����ڵ�����ռ���������Ƕ��٣���������������Ŀռ��뷵�� 0��
ʾ�� 1:
���룺grid = ["110","231","221"]
�����1
���ͣ�4 ������ռ��У�ֻ�� 1 �������������ڣ����Ϊ 1��
ʾ�� 2:
���룺grid = ["11111100000","21243101111","21224101221","11111101111"]
�����3
���ͣ�8 ������ռ��У��� 5 �������������ڣ�����ֱ�Ϊ 3��1��1��1��2��������Ϊ 3��
��ʾ��
1 <= grid.length <= 500
1 <= grid[i].length <= 500
grid[i][j] �������� "0"��"5"
*/

class Solution {
    int area = 0, flag = 1;  // area �ռ���� flag = 1 �����������ڿռ�
    void DFS(vector<string> &grid, char visited, int x, int y)
    {
        grid[x][y] = '6';   //�������ĵ�'6'
        area++;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size() || grid[a][b] == '0') 
                flag = 0;   // �������ȣ�flag = 0,�ÿռ������Ч
            if (a >= 0 && b >= 0 && a < grid.size() && b < grid[0].size() && grid[a][b] == visited ) 
                DFS(grid, grid[a][b], a, b); 
        }
    }
public:
    int largestArea(vector<string>& grid) {
        int ret = 0, temp = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                 if (grid[i][j] != '6' && grid[i][j] != '0')
                 {
                     area = 0, flag = 1;
                     DFS(grid, grid[i][j], i, j);
                     if (flag)
                        ret = max(ret, area);
                 }
            }
        }
        return ret;
    }
};

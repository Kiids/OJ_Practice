/*
��ɫ��䡣��д������ʵ�����ͼƬ�༭�����֧�ֵġ���ɫ��䡱���ܡ�����һ����Ļ���Զ�ά�����ʾ��Ԫ��Ϊ��ɫֵ����һ�����һ���µ���ɫֵ��������ɫֵ������������Χ����ֱ��ԭ������ɫֵȫ���ı䡣
ʾ��1:
 ���룺
image = [[1,1,1],[1,1,0],[1,0,1]] 
sr = 1, sc = 1, newColor = 2
 �����[[2,2,2],[2,2,0],[2,0,1]]
 ����: 
��ͼ������м䣬(����(sr,sc)=(1,1)),
��·�������з������������ص����ɫ�������ĳ�2��
ע�⣬���½ǵ�����û�и���Ϊ2��
��Ϊ�����������������ĸ����������ʼ�����������ص㡣
˵����
image �� image[0] �ĳ����ڷ�Χ [1, 50] �ڡ�
�����ĳ�ʼ�㽫���� 0 <= sr < image.length �� 0 <= sc < image[0].length��
image[i][j] �� newColor ��ʾ����ɫֵ�ڷ�Χ [0, 65535]�ڡ�
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int val, int newColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != val || newColor == val)
            return;
        else
            image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, val, newColor);
        dfs(image, sr, sc - 1, val, newColor);
        dfs(image, sr + 1, sc, val, newColor);
        dfs(image, sr, sc + 1, val, newColor);
    }
};

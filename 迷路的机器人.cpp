/*
�����и�����������һ����������Ͻǣ����� r �� c �С�������ֻ�����»������ƶ����������ߵ�һЩ����ֹ���������ϰ�������һ���㷨��Ѱ�һ����˴����Ͻ��ƶ������½ǵ�·����
�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
����һ�����е�·����·���ɾ�����������кź��к���ɡ����Ͻ�Ϊ 0 �� 0 �С����û�п��е�·�������ؿ����顣
ʾ�� 1:
����:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
���: [[0,0],[0,1],[0,2],[1,2],[2,2]]
����: 
�����б�ֵ�λ�ü�Ϊ�����ʾ��·������
0��0�У����Ͻǣ� -> 0��1�� -> 0��2�� -> 1��2�� -> 2��2�У����½ǣ�
˵����r �� c ��ֵ�������� 100��
*/

// DFS + ��֦ 
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& a)
    {
        vector<vector<int>> ret;
        if (a.size() == 0 || a[0].size() == 0)
            return ret;
        
        DFS(a, 0, 0, ret);
        return ret;
    }
    bool DFS(vector<vector<int>>& a, int i, int j, vector<vector<int>>& ret)
    {
        if (a[i][j] == 1)
            return false;
        
        ret.emplace_back(vector<int>({i, j}));
        if (i + 1 == a.size() && j + 1 == a[0].size())
            return true;
        
        if (i + 1 < a.size() && DFS(a, i + 1, j, ret))
            return true;
        
        if (j + 1 < a[0].size() && DFS(a, i, j + 1, ret))
            return true;
        
        ret.pop_back();
        a[i][j] = 1;
        return false;
    }
};

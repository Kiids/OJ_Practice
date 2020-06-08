/*
你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
示例：
输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：
0 < len(land) <= 1000
0 < len(land[i]) <= 1000
*/

class Solution {
public:
    vector<int> water;
    int count;
    vector<int> pondSizes(vector<vector<int>>& land)
    {
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] == 0)
                {
                    count = 0;
                    dfs(land, i, j);
                    water.push_back(count);
                }
            }
        }
        sort(water.begin(), water.end());
        return water;
    }
    void dfs(vector<vector<int>>& land, int i, int j)
    {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size())
            return;
        if(land[i][j]==0)
            ++count;
        else
            return;
        land[i][j] = 1;
        dfs(land, i, j + 1);
        dfs(land, i, j - 1);
        dfs(land, i-1, j + 1);
        dfs(land, i - 1, j - 1);
        dfs(land, i-1, j);
        dfs(land, i+1, j + 1);
        dfs(land, i+1, j );
        dfs(land, i+1, j - 1);
    }
};
/*
循环搜索，当碰到一个0的时候，采用dfs遍历连接的所有0
遍历完成以后把遍历过得0置一。
注意dfs的递归出口是 范围超界 和 格子不是water;
再回顾一下dfs的两种形式：递归是前面置1,迭代是后边置1
sort是递增序列
*/


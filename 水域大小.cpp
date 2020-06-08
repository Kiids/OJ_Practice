/*
����һ�����ڱ�ʾһƬ���ص���������land���þ�����ÿ�����ֵ�����Ӧ�ص�ĺ��θ߶ȡ���ֵΪ0���ʾˮ���ɴ�ֱ��ˮƽ��Խ����ӵ�ˮ��Ϊ�����������Ĵ�С��ָ�����ӵ�ˮ��ĸ�������дһ��������������������г����Ĵ�С������ֵ��Ҫ��С��������
ʾ����
���룺
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
����� [1,2,4]
��ʾ��
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
ѭ��������������һ��0��ʱ�򣬲���dfs�������ӵ�����0
��������Ժ�ѱ�������0��һ��
ע��dfs�ĵݹ������ ��Χ���� �� ���Ӳ���water;
�ٻع�һ��dfs��������ʽ���ݹ���ǰ����1,�����Ǻ����1
sort�ǵ�������
*/


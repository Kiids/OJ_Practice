/*
����ƽ���� n �Բ�ͬ�ĵ㣬�������ڡ� ���ɵ��ʾ��Ԫ�� (i, j, k) ������ i �� j ֮��ľ���� i �� k ֮��ľ�����ȣ���Ҫ����Ԫ���˳�򣩡�
�ҵ����л����ڵ�����������Լ��� n ���Ϊ 500�����е�������ڱ����� [-10000, 10000] �С�
ʾ��:
����:
[[0,0],[1,0],[2,0]]
���:
2
����:
����������Ϊ [[1,0],[0,0],[2,0]] �� [[1,0],[2,0],[0,0]]

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                m[x * x + y * y]++;
            }
            for (auto e : m)
                ret += e.second * (e.second - 1);
        }
        return ret;
    }
};

/*
������ xy ƽ���ϵ�һ��㣬ȷ������Щ����ɵľ��ε���С��������о��εı�ƽ���� x ��� y �ᡣ
���û���κξ��Σ��ͷ��� 0��
ʾ�� 1��
���룺[[1,1],[1,3],[3,1],[3,3],[2,2]]
�����4
ʾ�� 2��
���룺[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
�����2
��ʾ��
1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
���еĵ㶼�ǲ�ͬ�ġ�
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> s;
        for (vector<int>& point: points)
            s.emplace(40001 * point[0] + point[1]);

        int len = points.size(), ret = INT_MAX;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
                    if (s.count(points[i][0] * 40001 + points[j][1]) && s.count(points[j][0] * 40001 + points[i][1]))
                        ret = min(ret, abs(points[j][1] - points[i][1]) * abs(points[j][0] - points[i][0]));

        return ret < INT_MAX ? ret: 0;
    }
};

//��ȷ����������Ϊ�Խ��ߣ�Ȼ��ȥ�������������Ƿ���ڣ���������Կ��ټ������
//���ٲ��ҷ�ʽ: Ԥ�Ȱ��յ�ȥ����ȥ�洢��set����ǵ���Χ����һ�����־Ϳ��Ա�����


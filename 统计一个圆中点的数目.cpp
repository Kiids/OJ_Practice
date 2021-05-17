/*
����һ������ points ������ points[i] = [xi, yi] ����ʾ�� i �����ڶ�άƽ���ϵ����ꡣ�������ܻ��� ��ͬ �����ꡣ
ͬʱ����һ������ queries ������ queries[j] = [xj, yj, rj] ����ʾһ��Բ���� (xj, yj) �Ұ뾶Ϊ rj ��Բ��
����ÿһ����ѯ queries[j] �������ڵ� j ��Բ �� �����Ŀ�����һ������Բ�� �߽��� ������ͬ����Ϊ����Բ �� ��
���㷵��һ������ answer ������ answer[j]�ǵ� j ����ѯ�Ĵ𰸡�
ʾ�� 1��
���룺points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
�����[3,2,2]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��
ʾ�� 2��
���룺points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
�����[2,3,2,4]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��queries[3] ����ɫ��Բ��
��ʾ��
1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
���е����궼��������
*/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> v;
    	for (int i = 0; i < queries.size(); i++)
    	{
    		int tmp = 0;
    		int x = queries[i][0], y = queries[i][1], r = queries[i][2];
    		for (int j = 0; j < points.size(); j++)
    		{
    			int px = points[j][0], py = points[j][1];
    			if (pow((px - x), 2) + pow((py - y), 2) <= pow(r, 2))
    				tmp++;
    		}
    		v.push_back(tmp);
    	}
    	return v;
    }
};

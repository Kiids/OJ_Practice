/*
�������������ļ��ϣ�������ȡ��������������Σ���������ɵ���������ε������
ʾ��:
����: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
���: 2
����: 
�����������ͼ��ʾ����ɵĳ�ɫ�����������ģ����Ϊ2��
ע��:
3 <= points.length <= 50.
�������ظ��ĵ㡣
 -50 <= points[i][j] <= 50.
������ֵ�� 10^-6 ���ڶ���Ϊ����ȷ�𰸡�
*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double mmax = 0;
        for (int i = 0; i < points.size(); i ++)
            for (int j = i + 1; j < points.size(); j ++)
                for (int k = j + 1; k < points.size(); k ++) 
                    mmax = max(mmax, 0.5 * abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] + points[j][0] * points[k][1] - points[i][0] * points[k][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0]));
        return mmax;
    }
};

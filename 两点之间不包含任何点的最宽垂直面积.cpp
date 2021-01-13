/*
���� n ����άƽ���ϵĵ� points ������ points[i] = [xi, yi] �����㷵������֮���ڲ��������κε�� ���ֱ��� �Ŀ�ȡ�
��ֱ��� �Ķ����ǹ̶���ȣ��� y �������������һ������Ҳ���Ǹ߶�Ϊ����󣩡� ���ֱ��� Ϊ�������һ����ֱ�����
��ע�⣬��ֱ���� ���� �ĵ� ���� �����ڡ�
ʾ�� 1��
���룺points = [[8,7],[9,9],[7,4],[9,7]]
�����1
���ͣ���ɫ�������ɫ��������������
ʾ�� 2��
���룺points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
�����3
��ʾ��
n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi <= 109
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ret = 0;
        sort(points.begin(), points.end());
        for (int i = 1; i < points.size(); i++)
            ret = max(ret, points[i][0] - points[i - 1][0]);
        return ret;
    }
};

/*
�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�
����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�
ʾ�� 1��
���룺[[1,1],[2,3],[3,2]]
�����true
ʾ�� 2��
���룺[[1,1],[2,2],[3,3]]
�����false
��ʾ��
points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //б�ʹ�ʽ���� (x3-x2)(y2-y1) = (x2-x1)(y3-y2)
        return (points[2][0] - points[1][0]) * (points[1][1] - points[0][1]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};

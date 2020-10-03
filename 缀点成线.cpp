/*
��һ�� XY ����ϵ����һЩ�㣬���������� coordinates ���ֱ��¼���ǵ����꣬���� coordinates[i] = [x, y] ��ʾ������Ϊ x��������Ϊ y �ĵ㡣
�������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϣ����򷵻� true�������뷵�� false��
ʾ�� 1��
���룺coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
�����true
ʾ�� 2��
���룺coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
�����false
��ʾ��
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates �в����ظ��ĵ�
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double a, b, c, d;
        a = coordinates[0][0];
        b = coordinates[0][1];
        c = coordinates[1][0];
        d = coordinates[1][1];
        for (auto i : coordinates)
            if ((i[1] - b) * (c - a) != (i[0] - a) * (d - b))
                return false;
        return true;
    }
};

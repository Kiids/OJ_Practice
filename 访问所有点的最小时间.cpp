/*
ƽ������ n ���㣬���λ�������������ʾ points[i] = [xi, yi]������������������Щ����Ҫ����Сʱ�䣨����Ϊ��λ����
����԰�������Ĺ�����ƽ�����ƶ���
ÿһ����ˮƽ������ֱ�����ƶ�һ����λ���ȣ����߿���Խ��ߣ����Կ�����һ������ˮƽ����ֱ������ƶ�һ����λ���ȣ���
���밴�������г��ֵ�˳����������Щ�㡣
ʾ�� 1��
���룺points = [[1,1],[3,4],[-1,0]]
�����7
���ͣ�һ����ѵķ���·���ǣ� [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
�� [1,1] �� [3,4] ��Ҫ 3 �� 
�� [3,4] �� [-1,0] ��Ҫ 4 ��
һ����Ҫ 7 ��
ʾ�� 2��
���룺points = [[3,2],[-2,2]]
�����5
��ʾ��
points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0, pre_x = points[0][0], pre_y = points[0][1],curr_x,curr_y;
        for (int i = 0; i < points.size(); i++)
        {
            curr_x = points[i][0];
            curr_y = points[i][1];
            ret += max(abs(pre_x - curr_x), abs(pre_y - curr_y));
            pre_x = curr_x;
            pre_y = curr_y;
        }
        return ret;
    }
};

/*
������һ����ƽ���ϵĵ���ɵ��б� points����Ҫ�����ҳ� K ������ԭ�� (0, 0) ����ĵ㡣
�����ƽ��������֮��ľ�����ŷ����¾��롣��
����԰��κ�˳�򷵻ش𰸡����˵������˳��֮�⣬��ȷ����Ψһ�ġ�
ʾ�� 1��
���룺points = [[1,3],[-2,2]], K = 1
�����[[-2,2]]
���ͣ� 
(1, 3) ��ԭ��֮��ľ���Ϊ sqrt(10)��
(-2, 2) ��ԭ��֮��ľ���Ϊ sqrt(8)��
���� sqrt(8) < sqrt(10)��(-2, 2) ��ԭ�������
����ֻ��Ҫ����ԭ������� K = 1 ���㣬���Դ𰸾��� [[-2,2]]��
ʾ�� 2��
���룺points = [[3,3],[5,-1],[-2,4]], K = 2
�����[[3,3],[-2,4]]
���� [[-2,4],[3,3]] Ҳ�ᱻ���ܡ���
��ʾ��
1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        for (int i = 0; i < points.size(); i++)
        {
            int t = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (heap.size() < k)
                heap.push({t, i});
            else
                if (t<heap.top().first)
                {
                    heap.pop();
                    heap.push({t, i});
                }
        }
        while (!heap.empty())
        {
            v.push_back(points[heap.top().second]);
            heap.pop();
        }
        return v;
    }
};

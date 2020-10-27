/*
���ι���·������ n ��վ��������� 0 �� n - 1 ���б�š�������֪ÿһ�����ڹ���վ֮��ľ��룬distance[i] ��ʾ���Ϊ i �ĳ�վ�ͱ��Ϊ (i + 1) % n �ĳ�վ֮��ľ��롣
�����ϵĹ����������԰�˳ʱ�����ʱ��ķ�����ʻ��
���س˿ʹӳ����� start ��Ŀ�ĵ� destination ֮�����̾��롣
ʾ�� 1��
���룺distance = [1,2,3,4], start = 0, destination = 1
�����1
���ͣ�����վ 0 �� 1 ֮��ľ����� 1 �� 9����Сֵ�� 1��
ʾ�� 2��
���룺distance = [1,2,3,4], start = 0, destination = 2
�����3
���ͣ�����վ 0 �� 2 ֮��ľ����� 3 �� 7����Сֵ�� 3��
ʾ�� 3��
���룺distance = [1,2,3,4], start = 0, destination = 3
�����4
���ͣ�����վ 0 �� 3 ֮��ľ����� 6 �� 4����Сֵ�� 4��
��ʾ��
1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int x = 0, y = 0;
        for (auto e : distance)
            x += e;
        for (int t = start; t % distance.size() != destination; t++)
        {
            t = t % distance.size();
            y += distance[t];
        }
        return (x - y) >= y ? y : x - y;
    }
};
// ѭ��һ�����ܺͣ�ѭ��������˳ʱ����룬����˳ʱ��������ʱ������е���Сֵ��

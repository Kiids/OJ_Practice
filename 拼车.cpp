/*
��������� capacity ������λ���� ֻ�� ��һ��������ʻ��Ҳ����˵���������ͷ��ı䷽��
�������� capacity ��һ������ trips ,  trip[i] = [numPassengersi, fromi, toi] ��ʾ�� i �������� numPassengersi �˿ͣ������Ǻͷ����ǵ�λ�÷ֱ��� fromi �� toi ����Щλ���Ǵ������ĳ�ʼλ���򶫵Ĺ�������
���ҽ�������������и������г��н������г˿�ʱ������ true�������뷵�� false��
ʾ�� 1��
���룺trips = [[2,1,5],[3,3,7]], capacity = 4
�����false
ʾ�� 2��
���룺trips = [[2,1,5],[3,3,7]], capacity = 5
�����true
��ʾ��
1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 10^5
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001, 0);
        for (auto trip : trips)
        {
            v[trip[1]] += trip[0];
            v[trip[2]] -= trip[0];
            int sum = 0;
            for (auto value : v)
            {
                sum += value;
                if (sum > capacity)
                    return false;
            }
        }
        return true;
    }
};

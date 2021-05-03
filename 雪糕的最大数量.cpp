/*
�������ף�С�к� Tony ����һЩѩ�������
�̵����µ� n ֧ѩ�⣬�ó���Ϊ n ������ costs ��ʾѩ��Ķ��ۣ����� costs[i] ��ʾ�� i ֧ѩ����ֽ�۸�Tony һ���� coins �ֽ�����������ѣ�����Ҫ�򾡿��ܶ��ѩ�⡣
����۸����� costs ���ֽ��� coins ��������㲢���� Tony �� coins �ֽ��ܹ��򵽵�ѩ��� ������� ��
ע�⣺Tony ���԰�����˳����ѩ�⡣
ʾ�� 1��
���룺costs = [1,3,2,4,1], coins = 7
�����4
���ͣ�Tony �������±�Ϊ 0��1��2��4 ��ѩ�⣬�ܼ�Ϊ 1 + 3 + 2 + 1 = 7
ʾ�� 2��
���룺costs = [10,6,8,7,7,8], coins = 5
�����0
���ͣ�Tony û���㹻��Ǯ���κ�һ֧ѩ�⡣
ʾ�� 3��
���룺costs = [1,6,3,1,2,5], coins = 20
�����6
���ͣ�Tony �����������е�ѩ�⣬�ܼ�Ϊ 1 + 6 + 3 + 1 + 2 + 5 = 18 ��
��ʾ��
costs.length == n
1 <= n <= 10^5
1 <= costs[i] <= 10^5
1 <= coins <= 10^8
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
    	int ret = 0;
    	for (int i = 0; i < costs.size(); i++)
    	{
    		if ((coins - costs[i]) >= 0)
            {
    			ret++;
    			coins -= costs[i];
    		}
            else
    			break;
    	}
    	return ret;
    }
};

/*
����һ������ prices ������ prices[i] ���̵���� i ����Ʒ�ļ۸�
�̵������ڽ��д�����������Ҫ��� i ����Ʒ����ô����Եõ��� prices[j] ��ȵ��ۿۣ����� j ������ j > i �� prices[j] <= prices[i] �� ��С�±� �����û������������ j ���㽫û���κ��ۿۡ�
���㷵��һ�����飬�����е� i ��Ԫ�����ۿۺ��㹺����Ʒ i ������Ҫ֧���ļ۸�
ʾ�� 1��
���룺prices = [8,4,6,2,3]
�����[4,2,4,2,3]
���ͣ�
��Ʒ 0 �ļ۸�Ϊ price[0]=8 ���㽫�õ� prices[1]=4 ���ۿۣ��������ռ۸�Ϊ 8 - 4 = 4 ��
��Ʒ 1 �ļ۸�Ϊ price[1]=4 ���㽫�õ� prices[3]=2 ���ۿۣ��������ռ۸�Ϊ 4 - 2 = 2 ��
��Ʒ 2 �ļ۸�Ϊ price[2]=6 ���㽫�õ� prices[3]=2 ���ۿۣ��������ռ۸�Ϊ 6 - 2 = 4 ��
��Ʒ 3 �� 4 ��û���ۿۡ�
ʾ�� 2��
���룺prices = [1,2,3,4,5]
�����[1,2,3,4,5]
���ͣ�����������У�������Ʒ��û���ۿۡ�
ʾ�� 3��
���룺prices = [10,1,1,6]
�����[9,0,1,6]
��ʾ��
1 <= prices.length <= 500
1 <= prices[i] <= 10^3
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ret(prices.size());
        prices.push_back(0);
        stack<int> s;
        for (int i = 0; i < prices.size(); i ++)
        {
            while (!s.empty() && prices[i] <= prices[s.top()])
            {
                ret[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};

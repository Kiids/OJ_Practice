/*
С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�
����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
������� ��� �ܺȵ�����ƿ�ơ�
ʾ�� 1��
���룺numBottles = 9, numExchange = 3
�����13
���ͣ�������� 3 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 9 + 3 + 1 = 13 ƿ�ơ�
ʾ�� 2��
���룺numBottles = 15, numExchange = 4
�����19
���ͣ�������� 4 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 15 + 3 + 1 = 19 ƿ�ơ�
ʾ�� 3��
���룺numBottles = 5, numExchange = 5
�����6
ʾ�� 4��
���룺numBottles = 2, numExchange = 3
�����2
��ʾ��
1 <= numBottles <= 100
2 <= numExchange <= 100
*/

// ���ƿ��ֵ��1���Ƶļ۸����numExchange - 1����Ϊ���϶���ʣһ�����ϵ�ƿ�ӣ�����ӵ�е��ܼ�ֵΪn * numExchange - 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return (numBottles * numExchange - 1) / (numExchange - 1);
    }
};

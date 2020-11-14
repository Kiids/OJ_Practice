/*
��������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ����ܲ�����ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��
����һ����̳����ʾΪһ���������0��1������0��ʾû��ֲ����1��ʾ��ֲ�˻�������һ���� n ���ܷ��ڲ�������ֲ�������������� n �仨�����򷵻�True�������򷵻�False��
ʾ�� 1:
����: flowerbed = [1,0,0,0,1], n = 1
���: True
ʾ�� 2:
����: flowerbed = [1,0,0,0,1], n = 2
���: False
ע��:
���������ֺõĻ�����Υ����ֲ����
��������鳤�ȷ�ΧΪ [1, 20000]��
n �ǷǸ��������Ҳ��ᳬ����������Ĵ�С��
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =  0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};

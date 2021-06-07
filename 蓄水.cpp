/*
���� N �����������ҳ�ʼ���յ�ˮ�ף�ÿ��ˮ������һ��ˮͰ������ˮ���� i ��ˮ���䱸��ˮͰ�������� bucket[i]��С�����������ֲ�����
����ˮͰ��ѡ������һ��ˮͰ��ʹ����������Ϊ bucket[i]+1
��ˮ����ȫ��ˮͰ����ˮ��������Զ�Ӧ��ˮ��
ÿ��ˮ�׶�Ӧ�����ˮ������ vat[i]������С��������Ҫ���ٴβ��������������ˮ����ˮҪ��
ע�⣺ʵ����ˮ�� �ﵽ�򳬹� �����ˮ�����������ˮҪ��
ʾ�� 1��
���룺bucket = [1,3], vat = [6,8]
�����4
���ͣ�
�� 1 �β������� bucket[0]��
�� 2 ~ 4 �β�����ѡ����ˮ�����������ˮҪ��
ʾ�� 2��
���룺bucket = [9,0,1], vat = [0,2,2]
�����3
���ͣ�
�� 1 �β�����ѡ������ bucket[1]
�� 2~3 �β���ѡ����ˮ�����������ˮҪ��
��ʾ��
1 <= bucket.length == vat.length <= 100
0 <= bucket[i], vat[i] <= 10^4
*/

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int maxVat = 0, ret = INT_MAX;
        for (int v : vat)
            maxVat = max(maxVat, v);
        if (maxVat == 0)
            return 0;
        for (int i = 1; i <= maxVat; i++)
        {
            int add = 0;
            for (int j = 0; j < vat.size(); j++)
            {
                int expBucket = vat[j] % i == 0 ? vat[j] / i : vat[j] / i + 1;
                add += max(expBucket - bucket[j], 0);
            }
            ret = min(ret, add + i);
        }
        return ret;
    }
};

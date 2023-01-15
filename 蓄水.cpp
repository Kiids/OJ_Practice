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
                int expBucket = vat[j] % i == 0 ? vat[j] / i : vat[j] / i + 1;  // ö����ˮ����
                add += max(expBucket - bucket[j], 0);                           // ��������
            }
            ret = min(ret, add + i);
        }
        return ret;
    }
};

// ��Ȼ���С�����ˮͰ���Ĳ����ڡ���ˮ������֮ǰ
// ö�١���ˮ�����������Ƴ�ÿ��ˮͰ���������������������ˮͰ���Ĳ�������
// ö�١���ˮ���Ĵ��� k����ô��������Ϊ v ��ˮ�ף���������Ҫһ������Ϊ v / k ����ȡ����
// ���������ÿ��ˮͰ��Ҫ�����������ٴ�

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int time = 0;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < bucket.size(); i++)
        {
            if (vat[i] == 0)
                continue;
            if (bucket[i] == 0)
            {
                time++;
                bucket[i]++;
            }
            pq.push({(vat[i] - 1) / bucket[i] + 1, bucket[i], i});
        }

        int ret = INT_MAX;
        while (!pq.empty())
        {
            auto q = pq.top();
            pq.pop();
            if (time >= ret)
                break;
            ret = min(ret, q[0] + time);

            int i = q[2];
            int x = q[1] + 1;
            pq.push({(vat[i] - 1) / x + 1, x, i});
            time++;
        }
        return ret == INT_MAX ? 0 : ret;
    }
};

// ��Ҫ����ˮͰ���ܴﵽ����ʱ�䣬��ô�����е�ˮ����֮ǰ������Ͱ
// ������Ҫ������ˮ��Ϊ�ο��������������ȶ���
// �����������Ĺ�ϵ����ȡ����ʹ��Ҫ��ˮ�������ĸ��ڶѶ���ÿ���ó�������ˮͰ��ͬʱ�����ʱ�Ĳ�������
// ��������ˮͰ�����ϼ�¼�͸������ٵĲ������������õ���


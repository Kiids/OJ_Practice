/*
����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i ƪ���ı����õĴ��������㲢���ظ��о��ߵ� h ָ����
����ά���ٿ��� h ָ���Ķ��壺h ���������ô�������һ��������Ա�� hָ����ָ���������� ��n ƪ�����У��ܹ��� h ƪ���ķֱ����������� h �Ρ�������� n - h ƪ����ÿƪ�����ô��� ������ h �Ρ�
��� h �ж��ֿ��ܵ�ֵ��h ָ�� �����������Ǹ���
ʾ�� 1��
���룺citations = [3,0,6,1,5]
�����3 
���ͣ����������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 3, 0, 6, 1, 5 �Ρ�
     �����о����� 3 ƪ����ÿƪ ���� �������� 3 �Σ�������ƪ����ÿƪ������ ������ 3 �Σ��������� h ָ���� 3��
ʾ�� 2��
���룺citations = [1,3,1]
�����1
��ʾ��
n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r)
        {
            int m = (l + r + 1) / 2;  // +1Ϊ�˱���n=1ʱ��������ѭ��
            int t = 0;
            for (auto x : citations)
                if (x >= m)
                    t++;
            if (t < m)
                r = m - 1;            // �����������������ұ߽�
            else
                l = m;                // ����������������߽�
        }
        return l;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sum = 0;
        vector<int> v(citations.size() + 1);
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= citations.size())
                v[citations.size()]++;
            else 
                v[citations[i]]++;
        }
        for (int i = citations.size(); i >= 0; i--)  // Ҫ��hָ�������ܴ����ԴӺ���ǰ����
        {
            sum += v[i];
            if (sum >= i)             // ������������
                return i;
        }
        return 0;
    }
};

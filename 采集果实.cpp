/*
��ӭ��λ���������������ִ壬����ѵ������Ϊ���ɼ���ʵ����
�����ִ��У���λ������Ҫ�ɼ�һЩ��ʵ������ҩ����time[i] ��ʾ����ÿ�βɼ� 1��limit �ŵ� i �����͵Ĺ�ʵ��Ҫ��ʱ�䣨��ÿ�������Բɼ� limit �Ź�ʵ����
��ǰ������Ҫ��ɡ��ɼ���������ʵ�������� fruits[j] = [type, num] ��ʾ�� j ����Ҫ�ɼ� num �� type ���͵Ĺ�ʵ���ɼ��������£�
�� fruits ������˳�����βɼ�ÿһ����
�ɼ��굱ǰ���εĹ�ʵ���ܿ�ʼ�ɼ���һ����
������ɵ�ǰ���εĲɼ�����ձ�����������Ĺ�ʵ����գ�
����㲢����������ɲɼ�����������Ҫ��ʱ�䡣
ʾ�� 1��
���룺time = [2,3,2], fruits = [[0,2],[1,4],[2,1]], limit = 3
�����10
���ͣ�
���ڵ������ɼ� 3 ��
�� 0 ����Ҫ�ɼ� 2 �ŵ� 0 ���͹�ʵ����Ҫ�ɼ� 1 �Σ���ʱΪ 2*1=2
�� 1 ����Ҫ�ɼ� 4 �ŵ� 1 ���͹�ʵ����Ҫ�ɼ� 2 �Σ���ʱΪ 3*2=6
�� 2 ����Ҫ�ɼ� 1 �ŵ� 2 ���͹�ʵ����Ҫ�ɼ� 1 �Σ���ʱΪ 2*1=2
�����ܺ�ʱ 2+6+2=10
ʾ�� 2��
���룺time = [1], fruits = [[0,3],[0,5]], limit = 2
�����5
���ͣ�
���ڵ������ɼ� 2 ��
�� 0 ����Ҫ�ɼ� 3 �ŵ� 0 ���͹�ʵ����Ҫ�ɼ� 2 �Σ���ʱΪ 1*2=2
�� 1 ����Ҫ�ɼ� 5 �ŵ� 0 ���͹�ʵ����Ҫ�ɼ� 3 �Σ���ʱΪ 1*3=3
�谴��˳�����βɼ������� 2+3=5
��ʾ��
1 <= time.length <= 100
1 <= time[i] <= 100
1 <= fruits.length <= 10^3
0 <= fruits[i][0] < time.length
1 <= fruits[i][1] < 10^3
1 <= limit <= 100
*/

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int ret = 0;
        for (auto& f : fruits)
            ret += time[f[0]] * ((1LL * f[1] + limit - 1) / limit);
        return ret;
    }
};

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int ret = 0;
        for (auto& f : fruits)
			ret += time[f[0]] * (f[1] / limit + bool(f[1] % limit));
        return ret;
    }
};


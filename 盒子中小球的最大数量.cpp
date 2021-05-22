/*
����һ������С�����߳��������� n ��С�򣬱�Ŵ� lowLimit ��ʼ���� highLimit ���������� lowLimit ��?highLimit ����?n == highLimit - lowLimit + 1�����������������ĺ��ӣ���Ŵ� 1 �� infinity ��
��Ĺ����ǽ�ÿ��С���������У����к��ӵı��Ӧ������С������ÿλ���ֵĺ͡����磬��� 321 ��С��Ӧ�������� 3 + 2 + 1 = 6 �ĺ��ӣ������ 10 ��С��Ӧ�������� 1 + 0 = 1 �ĺ��ӡ�
������������ lowLimit �� highLimit �����ط������С��ĺ����е�С������������ж�����Ӷ�����������С��ֻ�践��������һ���ӵ�С��������
ʾ�� 1��
���룺lowLimit = 1, highLimit = 10
�����2
���ͣ�
���ӱ�ţ�1 2 3 4 5 6 7 8 9 10 11 ...
С��������2 1 1 1 1 1 1 1 1 0  0  ...
��� 1 �ĺ��ӷ������С��С������Ϊ 2 ��
ʾ�� 2��
���룺lowLimit = 5, highLimit = 15
�����2
���ͣ�
���ӱ�ţ�1 2 3 4 5 6 7 8 9 10 11 ...
С��������1 1 1 1 2 2 1 1 1 0  0  ...
��� 5 �� 6 �ĺ��ӷ������С��ÿ�������е�С���������� 2 ��
ʾ�� 3��
���룺lowLimit = 19, highLimit = 28
�����2
���ͣ�
���ӱ�ţ�1 2 3 4 5 6 7 8 9 10 11 12 ...
С��������0 1 1 1 1 1 1 1 1 2  0  0  ...
��� 10 �ĺ��ӷ������С��С������Ϊ 2 ��
��ʾ��
1 <= lowLimit <= highLimit <= 105
*/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> v(46,0);
        for (int i = lowLimit; i <= highLimit; i++)
        {
            string s = to_string(i);
            int sum = 0;
            for (int j = 0; j < s.size(); j++)
                sum += s[j] - '0';
            v[sum]++;
        }
        int max = v[0];
        for (int i = 0; i < v.size(); i++)
            if (max < v[i])
                max = v[i];
        return max;
    }
};

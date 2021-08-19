/*
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�
����һ������ n �����غ�Ϊ n ����ȫƽ������ �������� ��
��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵����ֵ����һ�������Գ˵Ļ������磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�
ʾ�� 1��
���룺n = 12
�����3 
���ͣ�12 = 4 + 4 + 4
ʾ�� 2��
���룺n = 13
�����2
���ͣ�13 = 4 + 9
��ʾ��
1 <= n <= 10^4
*/

class Solution {
public:
    int numSquares(int n) {
        int maxNum = (int)sqrt(n);
        vector<int> v;
        for (int i = 1; i <= maxNum; i++)
            v.push_back((int)pow(i, 2));
        vector<int> ret(n+1, INT_MAX);
        ret[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j : v)
                if (i - j >= 0 && ret[i-j] != INT_MAX)
                    ret[i] = min(ret[i], ret[i - j] + 1);
        return ret[n];
    }
};

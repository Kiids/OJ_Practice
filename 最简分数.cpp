/*
����һ������ n �����㷵������ 0 �� 1 ֮�䣨������ 0 �� 1�������ĸС�ڵ���  n �� ��� ���� ������������ ���� ˳�򷵻ء�
ʾ�� 1��
���룺n = 2
�����["1/2"]
���ͣ�"1/2" ��Ψһһ����ĸС�ڵ��� 2 ����������
ʾ�� 2��
���룺n = 3
�����["1/2","1/3","2/3"]
ʾ�� 3��
���룺n = 4
�����["1/2","1/3","1/4","2/3","3/4"]
���ͣ�"2/4" ��������������Ϊ�����Ի���Ϊ "1/2" ��
ʾ�� 4��
���룺n = 1
�����[]
��ʾ��
1 <= n <= 100
*/

class Solution {
    int Fun(int x, int y)
    {
        return y > 0 ? gcd(y, x % y) : x;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (Fun(j, i) == 1)
                    v.push_back(to_string(j) + "/" + to_string(i));
        return v;
    }
};

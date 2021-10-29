/*
�����д� 1 �� n �� n ������������Щ��������һ������ perm���±�� 1 ��ʼ����ֻҪ������������ ֮һ �����������һ�� ���������� ��
perm[i] �ܹ��� i ����
i �ܹ��� perm[i] ����
����һ������ n �����ؿ��Թ���� �������� �� ���� ��
ʾ�� 1��
���룺n = 2
�����2
���ͣ�
�� 1 �������������� [1,2]��
    - perm[1] = 1 �ܱ� i = 1 ����
    - perm[2] = 2 �ܱ� i = 2 ����
�� 2 �������������� [2,1]:
    - perm[1] = 2 �ܱ� i = 1 ����
    - i = 2 �ܱ� perm[2] = 1 ����
ʾ�� 2��
���룺n = 1
�����1
��ʾ��
1 <= n <= 15
*/

class Solution {
    int visted[16], ret;
public:
    int countArrangement(int n) {
        ret = 0;
        memset(visted, 0, sizeof(visted));
        back_trace(1, n);
        return ret;
    }

    void back_trace(int idx, int n)
    {
        if (idx > n)
            ret++;
        for (int i = 1; i <= n; i++)
        {
            if (visted[i])
                continue;
            if (i % idx == 0 || idx % i == 0)
            {
                visted[i] = 1;
                back_trace(idx + 1, n);
                visted[i] = 0;
            }
        }
    }
};

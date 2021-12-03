/*
����ĳЩ�̶��� N��������� A ������ 1, 2, ..., N ��ɵ����У�ʹ�ã�
����ÿ�� i < j���������� k ���� i < k < j ʹ�� A[k] * 2 = A[i] + A[j]��
��ô���� A ��Ư�����顣
���� N����������Ư������ A����֤����һ������
ʾ�� 1��
���룺4
�����[2,1,4,3]
ʾ�� 2��
���룺5
�����[3,1,2,5,4]
��ʾ��
1 <= N <= 1000
*/

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1)
            return {1};
        vector<int> v(n);
        int i = 0;
        for (int x : beautifulArray((n + 1) / 2))
            v[i++] = 2 * x -1;
        for(int  x : beautifulArray(n / 2))
            v[i++] = 2 * x;
        return v;
    }
};

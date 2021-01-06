/*
ͳ������С�ڷǸ����� n ��������������
ʾ�� 1��
���룺n = 10
�����4
���ͣ�С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��
ʾ�� 2��
���룺n = 0
�����0
ʾ�� 3��
���룺n = 1
�����0
��ʾ��
0 <= n <= 5 * 106
*/
 
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> signs(n, true);
        for (int i = 2; i < n; i++)
        {
            if (signs[i])
            {
                count++;
                for (int j = i + i; j < n; j += i)
                    signs[j] = false;
            }
        }
        return count;
    }
};

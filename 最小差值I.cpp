/*
����һ���������� A������������е�ÿ��Ԫ�� A[i] ������һ���������� x ��-K <= x <= K�����Ӷ��õ�һ�������� B ��
�������� B �����ֵ����Сֵ֮����ܴ��ڵ���С��ֵ��
ʾ�� 1��
���룺A = [1], K = 0
�����0
���ͣ�B = [1]
ʾ�� 2��
���룺A = [0,10], K = 2
�����6
���ͣ�B = [2,8]
ʾ�� 3��
���룺A = [1,3,6], K = 3
�����0
���ͣ�B = [3,3,3] �� B = [4,4,4]
��ʾ��
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (A.empty())
            return 0;
        const auto [low, high] = minmax_element(A.begin(), A.end());
        return max(0, *high - *low - 2 * K);
    }
};

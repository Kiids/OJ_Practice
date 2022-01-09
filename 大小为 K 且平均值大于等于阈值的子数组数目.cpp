/*
����һ���������� arr ���������� k �� threshold ��
���㷵�س���Ϊ k ��ƽ��ֵ���ڵ��� threshold ����������Ŀ��
ʾ�� 1��
���룺arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
�����3
���ͣ������� [2,5,5],[5,5,5] �� [5,5,8] ��ƽ��ֵ�ֱ�Ϊ 4��5 �� 6 ����������Ϊ 3 ���������ƽ��ֵ��С�� 4 ��threshold ��ֵ)��
ʾ�� 2��
���룺arr = [1,1,1,1,1], k = 1, threshold = 0
�����5
ʾ�� 3��
���룺arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
�����6
���ͣ�ǰ 6 ������Ϊ 3 ��������ƽ��ֵ������ 5 ��ע��ƽ��ֵ����������
ʾ�� 4��
���룺arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
�����1
ʾ�� 5��
���룺arr = [4,4,4,4], k = 4, threshold = 1
�����1
��ʾ��
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int exp = k * threshold;  // ������С��
        int sum = 0, ret = 0;
        // ��ʼ����
        for (int i = 0; i < k; i++)
            sum += arr[i];
        ret += sum >= exp;

        for (int i = k; i < arr.size(); i++)
        {
            sum += -arr[i - k] + arr[i];
            ret += sum >= exp;
        }
        return ret;
    }
};

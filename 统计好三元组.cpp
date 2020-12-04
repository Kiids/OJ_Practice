/*
����һ���������� arr ���Լ� a��b ��c ��������������ͳ�����к���Ԫ���������
�����Ԫ�� (arr[i], arr[j], arr[k]) ��������ȫ������������Ϊ����һ�� ����Ԫ�� ��
0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
���� |x| ��ʾ x �ľ���ֵ��
���� ����Ԫ������� ��
ʾ�� 1��
���룺arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
�����4
���ͣ�һ���� 4 ������Ԫ�飺[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] ��
ʾ�� 2��
���룺arr = [1,1,2,2,3], a = 0, b = 0, c = 1
�����0
���ͣ�����������������������Ԫ�顣
��ʾ��
3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ret = 0;
        for (int i = 0; i <= arr.size() - 3; i++)
        {
            for (int j = i + 1; j <= arr.size() - 2; j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                    for (int k = j + 1; k < arr.size(); k++)
                        if (abs(arr[j] - arr[k]) <= b  &&  abs(arr[i] - arr[k]) <= c)
                            ret++;
                else
                    continue;
            }
        }
        return ret;
    }
};

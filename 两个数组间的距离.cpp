/*
���������������� arr1 �� arr2 ��һ������ d �����㷵����������֮��� ����ֵ ��
������ֵ�� ����Ϊ���ϴ˾���Ҫ���Ԫ����Ŀ������Ԫ�� arr1[i] ���������κ�Ԫ�� arr2[j] ���� |arr1[i]-arr2[j]| <= d ��
ʾ�� 1��
���룺arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
�����2
���ͣ�
���� arr1[0]=4 �����У�
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
���� arr1[0]=4 ���Ͼ���Ҫ��
���� arr1[1]=5 �����У�
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
���� arr1[1]=5 Ҳ���Ͼ���Ҫ��
���� arr1[2]=8 �����У�
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
���ھ���С�ڵ��� 2 ������������Ͼ���Ҫ�� 
�ʶ�ֻ�� arr1[0]=4 �� arr1[1]=5 �������Ͼ���Ҫ�󣬾���ֵΪ 2
ʾ�� 2��
���룺arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
�����2
ʾ�� 3��
���룺arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
�����1
��ʾ��
1 <= arr1.length, arr2.length <= 500
-10^3 <= arr1[i], arr2[j] <= 10^3
0 <= d <= 100
*/

class Solution {
public:
     int biSch1(int l, int r, vector<int> arr, int target) {
        if (l >= r)
            return l;

        int m = (l + r) >> 1;
        if (arr[m] == target)
            return m;
        return arr[m] < target   biSch1(m + 1, r, arr, target) : biSch1(l, m, arr, target);
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0, n = arr2.size() - 1;
        sort(arr2.begin(), arr2.end());
        for (auto a : arr1)
        {
            int idx = biSch1(0, n, arr2, a);
            if (abs(arr2[idx] - a) <= d)
                continue;
            else
            {
                if (abs(arr2[max(0, idx - 1)] - a) <= d)
                    continue;
                else if (abs(arr2[min(idx + 1, n)] - a) <= d)
                    continue;
                ++ret;
            }
        }
        return ret;
    }
};

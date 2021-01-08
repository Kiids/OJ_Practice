/*
����һ���������� arr���������Ƿ������������ N �� M������ N �� M ������������N = 2 * M����
����ʽ�أ�����Ƿ���������±� i �� j ���㣺
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
ʾ�� 1��
���룺arr = [10,2,5,3]
�����true
���ͣ�N = 10 �� M = 5 ���������� 10 = 2 * 5 ��
ʾ�� 2��
���룺arr = [7,1,14,11]
�����true
���ͣ�N = 14 �� M = 7 ���������� 14 = 2 * 7 ��
ʾ�� 3��
���룺arr = [3,1,7,11]
�����false
���ͣ��ڸ�����²����� N �� M ���� N = 2 * M ��
��ʾ��
2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        bool ret = false;
        auto i0 = lower_bound(arr.begin(), arr.end(), 0);
        for (auto i = i0 - 1; i > arr.begin() && !ret; i--)
            ret = binary_search(arr.begin(), i, (*i) * 2);
        for (auto i = i0; i < arr.end() - 1 && !ret; i++)
            ret = binary_search(i + 1, arr.end(), (*i) * 2);
        return ret;
    }
};

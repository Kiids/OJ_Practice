/*
����һ������ arr �����㽫ÿ��Ԫ�������ұ�����Ԫ���滻����������һ��Ԫ�أ��� -1 �滻��
��������滻���������㷵��������顣
ʾ����
���룺arr = [17,18,5,4,6,1]
�����[18,6,6,6,1,-1]
��ʾ��
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int t = arr[i];
            arr[i] = max;
            if (t > max)
                max = t;
        }
        return arr;
    }
};

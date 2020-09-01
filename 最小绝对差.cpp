/*
������������� arr������ÿ��Ԫ�ض� ����ͬ��
�����ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�
ʾ�� 1��
���룺arr = [4,2,1,3]
�����[[1,2],[2,3],[3,4]]
ʾ�� 2��
���룺arr = [1,3,6,10,15]
�����[[1,3]]
ʾ�� 3��
���룺arr = [3,8,-10,23,19,-4,-14,27]
�����[[-14,-10],[19,23],[23,27]]
��ʾ��
2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++)
            min_diff = std::min(min_diff, arr.at(i + 1) - arr.at(i));
            
        vector<vector<int>> ret;
        ret.reserve(arr.size());
        for (int i = 0; i < arr.size() - 1; i++)
            if (min_diff == (arr.at(i + 1) - arr.at(i)))
                ret.push_back(vector<int>{arr.at(i), arr.at(i + 1)});

        return ret;
    }
};

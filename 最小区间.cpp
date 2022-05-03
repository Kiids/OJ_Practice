/*
���� k �� �ǵݼ����� �������б��ҵ�һ�� ��С ���䣬ʹ�� k ���б��е�ÿ���б�������һ�������������С�
���Ƕ������ b-a < d-c ������ b-a == d-c ʱ a < c�������� [a,b] �� [c,d] С��
ʾ�� 1��
���룺nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
�����[20,24]
���ͣ� 
�б� 1��[4, 10, 15, 24, 26]��24 ������ [20,24] �С�
�б� 2��[0, 9, 12, 20]��20 ������ [20,24] �С�
�б� 3��[5, 18, 22, 30]��22 ������ [20,24] �С�
ʾ�� 2��
���룺nums = [[1,2,3],[1,2,3],[1,2,3]]
�����[1,1]
��ʾ��
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-10^5 <= nums[i][j] <= 10^5
nums[i] ���ǵݼ�˳������
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); k++)
            for (auto n : nums[k])
                ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> v;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); j++)
        {
            if (!count[ordered[j].second]++)
                k++;
            if (k == nums.size())
            { 
                while (count[ordered[i].second] > 1)
                    count[ordered[i++].second]--; // minialize range
                if (v.empty() || v[1] - v[0] > ordered[j].first - ordered[i].first)
                    v = vector<int>{ordered[i].first, ordered[j].first};
            }
        }
        return v;
    }
};

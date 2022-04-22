/*
����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�
�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������
ʾ�� 1��
���룺nums = [4,6,7,7]
�����[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
ʾ�� 2��
���룺nums = [4,4,3,2,1]
�����[[4,4]]
��ʾ��
1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/

class Solution {
    vector<int> path;
    vector<vector<int>> v;
    void Fun(vector<int>& nums, int index)
    {
        if (path.size() >= 2)
            v.push_back(path);
        unordered_set<int> s;
        for (int i = index; i < nums.size(); ++i)
        {
            if (!path.empty() && nums[i] < path.back() || s.count(nums[i]) == 1)
                continue;

            s.insert(nums[i]);
            path.push_back(nums[i]);
            Fun(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        Fun(nums, 0);  // ���� ���ݲ���
        return v;
    }
};

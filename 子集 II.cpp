/*
����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
ʾ�� 1��
���룺nums = [1,2,2]
�����[[],[1],[1,2],[1,2,2],[2],[2,2]]
ʾ�� 2��
���룺nums = [0]
�����[[],[0]]
��ʾ��
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
    vector<vector<int>> v;
    vector<int> t;
    void DFS(bool flag, int cur, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            v.push_back(t);
            return ;
        }
        DFS(false, cur + 1, nums);
        if (!flag && cur > 0 && nums[cur] == nums[cur - 1])
            return;
        t.push_back(nums[cur]);
        DFS(true, cur + 1, nums);
        t.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        DFS(false, 0, nums);
        return v;
    }
};

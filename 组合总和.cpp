/*
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е����ֿ����������ظ���ѡȡ��
˵����
�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1��
���룺candidates = [2,3,6,7], target = 7,
����⼯Ϊ��
[
  [7],
  [2,2,3]
]
ʾ�� 2��
���룺candidates = [2,3,5], target = 8,
����⼯Ϊ��
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
��ʾ��
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate �е�ÿ��Ԫ�ض��Ƕ�һ�޶��ġ�
1 <= target <= 500
*/

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void Backtrack(vector<int>& candidates, int target, int sum, int start)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            Backtrack(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ret.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        Backtrack(candidates, target, 0, 0);
        return ret;
    }
};

/*
����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��
ע�⣺�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1:
����: candidates = [10,1,2,7,6,1,5], target = 8,
���:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
ʾ�� 2:
����: candidates = [2,5,2,1,2], target = 5,
���:
[
[1,2,2],
[5]
]
��ʾ:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
    int n;
    vector<int> v;
    vector<vector<int>> ret;
public:
    void DFS(vector<int>& a, int target, int s)
    {
        if (target == 0)                             // �ܺ��ѴﵽĿ������׷���������
        {
            ret.emplace_back(v);
            return;
        }
        for (int i = s; i < n && target - a[i] >= 0; i++)
        {
            if (i != s && a[i] == a[i - 1])          // ��ǰ����ǰһ����ͬ����
                continue;
            v.emplace_back(a[i]);                    // ���������뵱ǰλ����
            DFS(a, target - a[i], i + 1);            // DFSʣ��Ŀ��������һλ��
            v.pop_back();                            // ����
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());  // ��������
        DFS(candidates, target, 0);
        return ret;
    }
};

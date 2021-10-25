/*
����һ���������� nums ��һ������ target ��
�������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��
���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��
ʾ�� 1��
���룺nums = [1,1,1,1,1], target = 3
�����5
���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
ʾ�� 2��
���룺nums = [1], target = 1
�����1
��ʾ��
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution {
public:
    int x, ret;
    int findTargetSumWays(vector<int>& nums, int target) {
        x = target;
        DFS(nums, 0, 0);
        return ret;
    }

    void DFS(vector<int>& v, int i, int sum){
        if (i == v.size())
        {
            if (sum == x)
                ret++;
            return;
        }
        int a = v[i];
        DFS(v, i + 1, sum + a);
        DFS(v, i + 1, sum - a);
    }
};

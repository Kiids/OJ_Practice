/*
����һ�����ܺ����ظ�Ԫ�ص��������飬Ҫ�����������������ֵ������� �����Լ������������һ�������������С�
ע�⣺
�����С���ܷǳ��� ʹ��̫�����ռ�Ľ������������ͨ�����ԡ�
ʾ��:
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);
// pick(3) Ӧ�÷������� 2,3 ���� 4��ÿ�������ķ��ظ���Ӧ����ȡ�
solution.pick(3);
// pick(1) Ӧ�÷��� 0����Ϊֻ��nums[0]����1��
solution.pick(1);
*/

class Solution {
public:
    vector<int>::iterator begin, end;
    Solution(vector<int>& nums) {
        begin = nums.begin();
        end = nums.end();
    }
    
    int pick(int target) {
        vector<int>::iterator cur = begin;
        int cnt = 1, ret = 0, i = 0;
        while (cur != end)
        {
            if (*cur == target)
            {
                if (rand() % cnt == 0)
                    ret = i;
                cnt++;
            }
            i++;
            cur++;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

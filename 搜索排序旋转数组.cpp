/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
ʾ�� 1:
����: nums = [4,5,6,7,0,1,2], target = 0
���: 4
ʾ�� 2:
����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;

            if (nums[l] <= nums[m])  // ǰ�벿��
            {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else  // ��벿��
            {
                if (target <= nums[r] && target > nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};

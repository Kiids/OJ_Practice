/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )��
��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��
ʾ�� 1:
����: nums = [2,5,6,0,0,1,2], target = 0
���: true
ʾ�� 2:
����: nums = [2,5,6,0,0,1,2], target = 3
���: false
����:
���� ������ת�������� ��������Ŀ�������е� nums  ���ܰ����ظ�Ԫ�ء�
���Ӱ�쵽�����ʱ�临�Ӷ��𣿻���������Ӱ�죬Ϊʲô��
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return true;

             if (nums[l] == nums[m]) {
                l++;
                continue;
            }

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
        return false;
    }
};

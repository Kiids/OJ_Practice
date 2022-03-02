/*
����һ���������� nums �������ҳ������г˻����ķǿ����������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
���������Ĵ���һ�� 32-λ ������
������ ����������������С�
ʾ�� 1:
����: nums = [2,3,-2,4]
���: 6
����: ������ [2,3] �����˻� 6��
ʾ�� 2:
����: nums = [-2,0,-1]
���: 0
����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣
��ʾ:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
nums ���κ�ǰ׺���׺�ĳ˻��� ��֤ ��һ�� 32-λ ����
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
            
        int x = nums[0], maxX = nums[0], minX = nums[0];
        for (int i = 1; i < n; i++)
        {
            int t = maxX;
            maxX = max(max(maxX * nums[i], nums[i]), minX * nums[i]);
            minX = min(min(t * nums[i], nums[i]), minX * nums[i]);
            x = max(maxX, x);
        }
        return x;
    }
};

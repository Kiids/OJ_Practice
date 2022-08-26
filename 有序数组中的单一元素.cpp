/*
����һ������������ɵ��������飬����ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Ρ�
�����ҳ�������ֻ����һ�ε��Ǹ�����
����ƵĽ�������������� O(log n) ʱ�临�ӶȺ� O(1) �ռ临�Ӷȡ�
ʾ�� 1:
����: nums = [1,1,2,3,3,4,4,8,8]
���: 2
ʾ�� 2:
����: nums =  [3,3,7,7,10,11,11]
���: 10
��ʾ:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m < n - 1 && nums[m] == nums[m + 1])
            {
                if ((n - m) & 1)
                    l = m + 2;  // ��2����Ϊ m + 1 == m ����ֱ������
                else
                    r = m - 1;
            }
            else if (m > 0 && nums[m] == nums[m - 1])
            {
                if (m & 1)
                    l = m +1 ;
                else
                    r = m - 2;
            }
            else
                return nums[m];
        }
        return 0;
    }
};

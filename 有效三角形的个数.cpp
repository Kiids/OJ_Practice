/*
����һ�������Ǹ����������飬���������ͳ�����п�����������������ߵ���Ԫ�������
ʾ�� 1:
����: [2,2,3,4]
���: 3
����:
��Ч�������: 
2,3,4 (ʹ�õ�һ�� 2)
2,3,4 (ʹ�õڶ��� 2)
2,2,3
ע��:
���鳤�Ȳ�����1000��
�����������ķ�ΧΪ [0, 1000]��
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int x = nums.size() - 1; x >= 2; x--) 
        {
            int i = 0, j = x - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[x])
                {
                    ret += j - i;
                    j--;
                }
                else
                    i++;
            }
        }
        return ret;
    }
};

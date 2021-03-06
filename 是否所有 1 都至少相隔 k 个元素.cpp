/*
����һ�������� 0 �� 1 ��ɵ����� nums �Լ����� k��������� 1 ��������� k ��Ԫ�أ��򷵻� True �����򣬷��� False ��
ʾ�� 1��
���룺nums = [1,0,0,0,1,0,0,1], k = 2
�����true
���ͣ�ÿ�� 1 ��������� 2 ��Ԫ�ء�
ʾ�� 2��
���룺nums = [1,0,0,1,0,1], k = 2
�����false
���ͣ��ڶ��� 1 �͵����� 1 ֮��ֻ���� 1 ��Ԫ�ء�
ʾ�� 3��
���룺nums = [1,1,1,1,1], k = 0
�����true
ʾ�� 4��
���룺nums = [0,1,0,1], k = 1
�����true
��ʾ��
1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] ��ֵΪ 0 �� 1
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = k + 1, x = -k - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                n = i - x;   
                x = i;
                if (n < k + 1)
                    return false;
            }
        }        
        return true;
    }
};

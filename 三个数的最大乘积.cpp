/*
����һ���������飬���������ҳ�����������ɵ����˻������������˻���
ʾ�� 1:
����: [1,2,3]
���: 6
ʾ�� 2:
����: [1,2,3,4]
���: 24
ע��:
�������������鳤�ȷ�Χ��[3,104]�����������е�Ԫ�ط�Χ��[-1000, 1000]��
����������������������ĳ˻����ᳬ��32λ�з��������ķ�Χ��
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;
        if (nums[1] < 0)
            max1 = nums[0] * nums[1] * nums[size - 1];
        max2 = nums[size - 1] * nums[size - 2] * nums[size - 3];        
        return max(max1, max2);
    }
};

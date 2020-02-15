/*
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
˵��:
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:
����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
���: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, l = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
                nums1[l--] = nums1[i--];
            else
                nums1[l--] = nums2[j--];
        }
        while (j >= 0)
            nums1[l--] = nums2[j--];  
    }
};

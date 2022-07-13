/*
���������������� nums1��nums2 �� nums3 �����㹹�첢����һ�� Ԫ�ظ�����ͬ�� ���飬���� ���� �� ���� �����г��ֵ�����ֵ��ɡ������е�Ԫ�ؿ��԰� ���� ˳�����С�
ʾ�� 1��
���룺nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
�����[3,2]
���ͣ����������������г��ֵ�����ֵΪ��
- 3 ����ȫ�����������ж����ֹ���
- 2 �������� nums1 �� nums2 �г��ֹ���
ʾ�� 2��
���룺nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
�����[2,3,1]
���ͣ����������������г��ֵ�����ֵΪ��
- 2 �������� nums2 �� nums3 �г��ֹ���
- 3 �������� nums1 �� nums2 �г��ֹ���
- 1 �������� nums1 �� nums3 �г��ֹ���
ʾ�� 3��
���룺nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
�����[]
���ͣ����������������������г��ֵ�ֵ��
��ʾ��
1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100
*/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int h[101] = {0};
        for (int i : nums1)
            h[i] |= 1;
        for (int i : nums2)
            h[i] |= 2;
        for (int i : nums3)
            h[i] |= 4;

        vector<int> v;
        for (int i = 1; i <= 100; i++)
            if (h[i] > 2 && h[i] != 4)
                v.push_back(i);
        return v;
    }
};

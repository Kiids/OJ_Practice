/*
�����������飬��дһ���������������ǵĽ�����
ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2]
ʾ�� 2��
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[9,4]
˵����
�������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳��
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int i : nums2) 
            if (nums1_set.count(i) == 1)
                set.insert(i);
        return vector<int>(set.begin(), set.end());
    }
};

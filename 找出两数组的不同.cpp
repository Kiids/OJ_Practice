/*
���������±�� 0 ��ʼ���������� nums1 �� nums2 �����㷵��һ������Ϊ 2 ���б� answer �����У�
answer[0] �� nums1 ������ �� ������ nums2 �е� ��ͬ ������ɵ��б�
answer[1] �� nums2 ������ �� ������ nums1 �е� ��ͬ ������ɵ��б�
ע�⣺�б��е��������԰� ���� ˳�򷵻ء�
ʾ�� 1��
���룺nums1 = [1,2,3], nums2 = [2,4,6]
�����[[1,3],[4,6]]
���ͣ�
���� nums1 ��nums1[1] = 2 ������ nums2 ���±� 0 ����Ȼ�� nums1[0] = 1 �� nums1[2] = 3 û�г����� nums2 �С���ˣ�answer[0] = [1,3]��
���� nums2 ��nums2[0] = 2 ������ nums1 ���±� 1 ����Ȼ�� nums2[1] = 4 �� nums2[2] = 6 û�г����� nums2 �С���ˣ�answer[1] = [4,6]��
ʾ�� 2��
���룺nums1 = [1,2,3,3], nums2 = [1,1,2,2]
�����[[3],[]]
���ͣ�
���� nums1 ��nums1[2] �� nums1[3] û�г����� nums2 �С����� nums1[2] == nums1[3] �����ߵ�ֵֻ��Ҫ�� answer[0] �г���һ�Σ��� answer[0] = [3]��
nums2 �е�ÿ���������� nums1 �г��֣���ˣ�answer[1] = [] �� 
��ʾ��
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x, y;
        set<int> a, b;
        for (auto& num : nums1)
            a.insert(num);
        for (auto& num : nums2)
            b.insert(num);
            
        for (auto& num : a)
            if (b.count(num) == 0)
                x.push_back(num);
        for (auto& num : b)
            if (a.count(num) == 0)
                y.push_back(num);
                
        return {x, y};
    }
};

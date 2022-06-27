/*
����һ���������� nums �������һ������ original ��������Ҫ�� nums �������ĵ�һ�����֡�
������������Ҫ���������������
����� nums ���ҵ� original ���� original?���� 2 ���õ��� original�������� original = 2 * original����
����ֹͣ��һ���̡�
ֻҪ�����������ҵ��� original ���Ͷ��� original ���� �ظ� ��һ���̡�
���� original �� ���� ֵ��
ʾ�� 1��
���룺nums = [5,3,6,1,12], original = 3
�����24
���ͣ� 
- 3 ���� nums ���ҵ���3 * 2 = 6 ��
- 6 ���� nums ���ҵ���6 * 2 = 12 ��
- 12 ���� nums ���ҵ���12 * 2 = 24 ��
- 24 ������ nums ���ҵ�����ˣ����� 24 ��
ʾ�� 2��
���룺nums = [2,7,9], original = 4
�����4
���ͣ�
- 4 ������ nums ���ҵ�����ˣ����� 4 ��
��ʾ��
1 <= nums.length <= 1000
1 <= nums[i], original <= 1000
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original))
            original *= 2;
        return original;
    }
};

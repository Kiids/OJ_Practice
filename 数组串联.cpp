/*
����һ������Ϊ n ���������� nums �����㹹��һ������Ϊ 2n �Ĵ����� ans �������±� �� 0 ��ʼ���� ����������?0 <= i < n �� i ��������������Ҫ��
ans[i] == nums[i]
ans[i + n] == nums[i]
������ԣ�ans ������ nums ���� ���� �γɡ�
�������� ans ��
ʾ�� 1��
���룺nums = [1,2,1]
�����[1,2,1,1,2,1]
���ͣ����� ans ��������ʽ�γɣ�
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
ʾ�� 2��
���룺nums = [1,3,2,1]
�����[1,3,2,1,1,3,2,1]
���ͣ����� ans ��������ʽ�γɣ�
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
��ʾ��
n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v = nums;
        nums.insert(nums.end(), v.begin(), v.end());
        return nums;
    }
};

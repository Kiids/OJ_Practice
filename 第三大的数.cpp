/*
����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
ʾ�� 1:
����: [3, 2, 1]
���: 1
����: ����������� 1.
ʾ�� 2:
����: [1, 2]
���: 2
����: ���������������, ���Է��������� 2 .
ʾ�� 3:
����: [2, 2, 3, 1]
���: 1
����: ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
��������ֵΪ2���������Ƕ��ŵڶ���
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = nums[0], second = INT_MIN, third = second;
        if (nums.size() == 3)  // ���⴦��[1,1,2] [1,2,INT_MIN]���
        {
            sort(nums.begin(), nums.end());
            if (nums[0] != nums[1] && nums[1] != nums[2])
                return nums[0];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n == first || n == second || n == third)
                continue;
            if (n > first)
            {
                third = second;
                second = first;
                first = n;
            }
            else if (n > second)
            {
                third = second;
                second = n;
            }
            else if (n > third)
                third = n;
        }
        return third == INT_MIN ? first : third;
    }
};

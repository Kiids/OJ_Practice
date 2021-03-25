/*
����һ����������ɵ����� nums ������ nums ��һ�� ���� �������������Ԫ�غ͡�
�������������е�һ�������������С�
��֪������ [numsl, numsl+1, ..., numsr-1, numsr] ���������� i��l <= i < r����numsi < numsi+1 �������������һ������Ϊ ���� �����顣ע�⣬��СΪ 1 ��������Ҳ���� ���� �����顣
ʾ�� 1��
���룺nums = [10,20,30,5,10,50]
�����65
���ͣ�[5,10,50] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 65 ��
ʾ�� 2��
���룺nums = [10,20,30,40,50]
�����150
���ͣ�[10,20,30,40,50] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 150 �� 
ʾ�� 3��
���룺nums = [12,17,15,13,10,11,12]
�����33
���ͣ�[10,11,12] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 33 �� 
ʾ�� 4��
���룺nums = [100,10,1]
�����100
��ʾ��
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 1, ret = INT_MIN;
        while (r < n)
        {
            if (nums[r] > nums[r - 1])
            {
                r++;
                continue;
            }
            int sum = accumulate(nums.begin() + l, nums.begin() + r, 0);
            ret = max(ret, sum);
            l = r;
            r++;
        }
        int sum = accumulate(nums.begin() + l, nums.end(), 0);
        ret = max(ret, sum);
        return ret;
    }
};

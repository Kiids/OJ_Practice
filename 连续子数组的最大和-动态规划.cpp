/*
����һ���������飬������������Ҳ�и����������е�һ������������������һ�������顣������������ĺ͵����ֵ��
Ҫ��ʱ�临�Ӷ�ΪO(n)��
ʾ��1:
����: nums = [-2,1,-3,4,-1,2,1,-5,4]
���: 6
����: ����������?[4,-1,2,1] �ĺ����Ϊ?6��
��ʾ��
1 <=?arr.length <= 10^5
-100 <= arr[i] <= 100
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ��̬�滮 ʱ��O(n) �ռ�O(1) 
        int max = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum > 0)  // ��ǰsum����0�������
                sum += nums[i];
            else  // �������滻Ϊ��Ԫ�ص�ֵ
                sum = nums[i];

            max = max > sum ? max : sum;
        }
        return max;
    }
};

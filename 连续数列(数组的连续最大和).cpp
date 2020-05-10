/*
����һ���������飬�ҳ��ܺ������������У��������ܺ͡�
ʾ����
���룺 [-2,1,-3,4,-1,2,1,-5,4]
����� 6
���ͣ� ���������� [4,-1,2,1] �ĺ����Ϊ 6��
���ף�
������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

// ��̬�滮  ��ԭ���鵱��dp��ֱ����ԭ�����ϸ�
// ״̬�� dp[i]��ʾ��i��β���������������
// ״̬ת�ƣ�
// ���ڵ�ǰ��nums[i]
// ���nums[i] >= 0 �� dp[i] = dp[i-1] + nums[i];
// ���� dp[i] = nums[i];
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= 0)
                nums[i] += nums[i - 1];
            ret = max(nums[i], ret);
        }
        return ret;
    }
}; 

// ���η�
int maxSubArray(vector<int>& nums)
{
    if (nums.size() == 0) 
		return INT_MIN;
    return divide(nums, 0, nums.size() - 1);
}
int divide(vector<int>& nums, int left, int right)
{
    if (left == right) 
		return nums[left];
    int mid = (left + right) / 2;
    // 1. ������к������
    int sumLeft = divide(nums, left, mid);
    // 2. ������к����ұ�
    int sumRight = divide(nums, mid + 1, right);
    // 3. ������к����м�
    // ������ߵ�����
    int leftSum = 0, leftMaxSum = INT_MIN;
    for (int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        leftMaxSum = max(leftMaxSum, leftSum);
    }
    // ���ұߵ�����
    int rightSum = 0,rightMaxSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        rightMaxSum = max(rightMaxSum, rightSum);
    }
    return max(max(sumLeft, sumRight), leftMaxSum + rightMaxSum);
}


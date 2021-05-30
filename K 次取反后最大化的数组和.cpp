/*
����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��ĳ������ i?���� A[i] �滻Ϊ -A[i]��Ȼ���ܹ��ظ�������� K �Ρ������ǿ��Զ��ѡ��ͬһ������ i����
�����ַ�ʽ�޸�����󣬷���������ܵ����͡�
ʾ�� 1��
���룺A = [4,2,3], K = 1
�����5
���ͣ�ѡ������ (1,) ��Ȼ�� A ��Ϊ [4,-2,3]��
ʾ�� 2��
���룺A = [3,-1,0,2], K = 3
�����6
���ͣ�ѡ������ (1, 2, 2) ��Ȼ�� A ��Ϊ [3,1,0,2]��
ʾ�� 3��
���룺A = [2,-3,-1,5,-4], K = 2
�����13
���ͣ�ѡ������ (1, 4) ��Ȼ�� A ��Ϊ [2,3,-1,5,4]��
��ʾ��
1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
*/

class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ret = 0;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            ret += nums[i];
        }
        if (k % 2 == 1)
            ret -= 2 * nums[nums.size() - 1];
        return ret;
    }
};

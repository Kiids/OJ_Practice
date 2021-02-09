/*
���� n ���������ҳ�ƽ��������ҳ���Ϊ k �����������飬����������ƽ������
ʾ����
���룺[1,12,-5,-6,50,3], k = 4
�����12.75
���ͣ����ƽ���� (12-5-6+50)/4 = 51/4 = 12.75
��ʾ��
1 <= k <= n <= 30,000��
�������ݷ�Χ [-10,000��10,000]��
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int ret = sum;
        for (int i = 1; i + k - 1 < n; i++)
        {
            sum += nums[i + k - 1] - nums[i - 1];
            ret = max(ret, sum);
        }
        return (double)ret / k;
    }
};
// �������� 

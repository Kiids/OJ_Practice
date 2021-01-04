/*
����һ������Ϊ n ���������飬�����ж��� ��� �ı� 1 ��Ԫ�ص�����£��������ܷ���һ���ǵݼ����С�
��������������һ���ǵݼ����еģ� �������������е� i (0 <= i <= n-2)�������� nums[i] <= nums[i + 1]��
ʾ�� 1:
����: nums = [4,2,3]
���: true
����: �����ͨ���ѵ�һ��4���1��ʹ������Ϊһ���ǵݼ����С�
ʾ�� 2:
����: nums = [4,2,1]
���: false
����: �㲻����ֻ�ı�һ��Ԫ�ص�����½����Ϊ�ǵݼ����С�
˵����
1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 2)
            return true;

        int n = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (n == 0)
                    return false;
                if (i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                n--;
            }
        }

        return true;
    }
};

//�ҵ��½���i֮�󣬷������������
//cnt�Ѿ���Ϊ0�ˣ�˵���ǵڶ����½��㣬ֱ�ӷ���false
//nums[i] > nums[i - 2]���޸�nums[i-1] = nums[i] (����קnums[i-1])
//nums[i] < nums[i - 2]���޸�nums[i] = nums[i - 1] (������nums[i])
//���ͨ��һ�����ϵ���������ק������ʹ֮�����򷵻�true������false��

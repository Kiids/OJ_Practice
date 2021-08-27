/*
���һ������ ����������Ԫ�� ������������������Ԫ��֮����ͬ����Ƹ�����Ϊ�Ȳ����С�
���磬[1,3,5,7,9]��[7,7,7,7] �� [3,-1,-5,-9] ���ǵȲ����С�
����һ���������� nums ���������� nums ������Ϊ�Ȳ������ ������ ������
������ �������е�һ���������С�
ʾ�� 1��
���룺nums = [1,2,3,4]
�����3
���ͣ�nums ���������ӵȲ����飺[1, 2, 3]��[2, 3, 4] �� [1,2,3,4] ����
ʾ�� 2��
���룺nums = [1]
�����0
��ʾ��
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int ret = 0, n = 1;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                ret += n++;
            else
                n = 1;
        }
        return ret;
    }
};

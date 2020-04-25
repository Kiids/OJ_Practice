/*
��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�
ʾ�� 1��
���룺nums = [3,4,3,3]
�����4
ʾ�� 2��
���룺nums = [9,1,7,9,7,9,7]
�����1
���ƣ�
1 <= nums.length <= 10000
1 <= nums[i] < 2^31
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = 0;
            for (int j = 0; j < nums.size(); j++)
                bit += (nums[j] >> i) & 1;
            ret |= (bit % 3) << i;
        }
        return ret;
    }
};

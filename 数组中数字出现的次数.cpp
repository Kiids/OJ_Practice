/*
һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
ʾ�� 1��
���룺nums = [4,1,4,6]
�����[1,6] �� [6,1]
ʾ�� 2��
���룺nums = [1,2,10,4,1,4,3,3]
�����[2,10] �� [10,2]
���ƣ�
2 <= nums <= 10000
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = nums[0];
        int b = 0;
        int c = 0;
        int n = 1;
        vector<int> ret(2, 0);
        for (int i = 1; i < nums.size(); i++)
            a ^=nums[i];     
        
        while (true)
        {
            if ((a & n) == n)
               //�ҵ�Ϊ 1 ��λ��
                break;
            n *= 2;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & n ) == n)
                b ^= nums[i];
            else
                c ^=nums[i];
        }
        
        ret[0] = b;
        ret[1] = c;
        return ret;
    }
};

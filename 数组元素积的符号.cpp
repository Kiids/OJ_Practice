/*
��֪���� signFunc(x) ������� x �����������ض�ֵ��
��� x ������������ 1 ��
��� x �Ǹ��������� -1 ��
��� x �ǵ��� 0 ������ 0 ��
����һ���������� nums ���� product Ϊ���� nums ������Ԫ��ֵ�ĳ˻���
���� signFunc(product) ��
ʾ�� 1��
���룺nums = [-1,-2,-3,-4,3,2,1]
�����1
���ͣ�����������ֵ�ĳ˻��� 144 ���� signFunc(144) = 1
ʾ�� 2��
���룺nums = [1,5,0,2,-3]
�����0
���ͣ�����������ֵ�ĳ˻��� 0 ���� signFunc(0) = 0
ʾ�� 3��
���룺nums = [-1,1,-1,1,-1]
�����-1
���ͣ�����������ֵ�ĳ˻��� -1 ���� signFunc(-1) = -1
��ʾ��
1 <= nums.length <= 1000
-100 <= nums[i] <= 100
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ret = 1;
        for (int e : nums)
        {
            if (e == 0)
            {
                ret = 0;
                break;
            }
            else if (e < 0)
                ret *= (-1);
        }
        return ret;
    }
};

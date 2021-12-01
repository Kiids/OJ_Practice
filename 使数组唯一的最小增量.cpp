/*
����һ���������� nums ��ÿ�� move ��������ѡ������һ������ 0 <= i < nums.length ���±� i������?nums[i] ����?1��
����ʹ nums �е�ÿ��ֵ�����Ψһ������Ҫ�����ٲ���������
ʾ�� 1��
���룺nums = [1,2,2]
�����1
���ͣ�����һ�� move ���������齫��Ϊ [1, 2, 3]��
ʾ�� 2��
���룺nums = [3,2,1,2,1,7]
�����6
���ͣ����� 6 �� move ���������齫��Ϊ [3, 4, 1, 2, 5, 7]��
���Կ��� 5 �λ� 5 �����µ� move �����ǲ����������ÿ��ֵΨһ�ġ�
��ʾ��
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(), v.end());
        int ret = 0;
        for (int i = 1; i < v.size(); i++)
        {
            int x = v[i - 1] + 1 - v[i];
            if (x > 0)
            {
                ret += x;
                v[i] += x;
            }
        }
        return ret;
    }
};

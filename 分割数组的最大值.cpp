/*
����һ���Ǹ��������� nums ��һ������ m ������Ҫ���������ֳ� m ���ǿյ����������顣
���һ���㷨ʹ���� m ����������Ժ͵����ֵ��С��
ʾ�� 1��
���룺nums = [7,2,5,10,8], m = 2
�����18
���ͣ�
һ�������ַ����� nums �ָ�Ϊ 2 �������顣 
������õķ�ʽ�ǽ����Ϊ [7,2,5] �� [10,8] ��
��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��
ʾ�� 2��
���룺nums = [1,2,3,4,5], m = 2
�����9
ʾ�� 3��
���룺nums = [1,4,4], m = 3
�����4
��ʾ��
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= m <= min(50, nums.length)
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long l = nums[0], r = 0;
        for (auto i : nums)
        {
            r += i;
            l = l > i ? l : i;
        }
        while (l < r)
        {
            long mid = (l + r) / 2;
            long t = 0;
            int cnt = 1;
            for (auto i : nums)
            {
                t += i;
                if (t > mid)
                {
                    t = i;
                    cnt++;
                }
            }
            if (cnt > m)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

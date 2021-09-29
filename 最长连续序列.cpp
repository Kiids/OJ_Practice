/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
ʾ�� 1��
���룺nums = [100,4,200,1,3,2]
�����4
���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
ʾ�� 2��
���룺nums = [0,3,7,2,5,8,4,6,0,1]
�����9
��ʾ��
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto e : nums)
            s.insert(e);
        int ret = 0;
        for (auto e : s)
        {
            if(!s.count(e - 1))
            {
                int t = e;
                while (s.count(t + 1))
                    t++;
                ret = max(ret, t - e + 1);
            }
        }
        return ret;
    }
};

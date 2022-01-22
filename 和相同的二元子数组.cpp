/*
����һ����Ԫ���� nums ����һ������ goal ������ͳ�Ʋ������ж��ٸ���Ϊ goal �� �ǿ� �����顣
������ �������һ���������֡�
ʾ�� 1��
���룺nums = [1,0,1,0,1], goal = 2
�����4
���ͣ�
�� 4 ��������ĿҪ��������飺[1,0,1]��[1,0,1,0]��[0,1,0,1]��[1,0,1]
ʾ�� 2��
���룺nums = [0,0,0,0,0], goal = 0
�����15
��ʾ��
1 <= nums.length <= 3 * 10^4
nums[i] ���� 0 ���� 1
0 <= goal <= nums.length
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        m[0]++;
        int ret = 0, n = 0;
        for (auto e : nums)
        {
            n += e;
            if (m[n - goal])
                ret += m[n - goal];  // ��������ö�ٵ�nums[i]������ֻ��Ҫ��ѯ��ϣ����Ԫ�� sum[i]-goal ����������
            m[n]++;
        }
        return ret;
    }
};
// ��ϣ�洢ǰ׺��
// �������ʵľ��ۼ�

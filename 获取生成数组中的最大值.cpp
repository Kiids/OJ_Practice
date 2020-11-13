/*
����һ������ n ����������������һ������Ϊ n + 1 ������ nums ��
nums[0] = 0
nums[1] = 1
�� 2 <= 2 * i <= n ʱ��nums[2 * i] = nums[i]
�� 2 <= 2 * i + 1 <= n ʱ��nums[2 * i + 1] = nums[i] + nums[i + 1]
������������ nums �е� ��� ֵ��
ʾ�� 1��
���룺n = 7
�����3
���ͣ����ݹ���
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
��ˣ�nums = [0,1,1,2,1,3,2,3]�����ֵ 3
ʾ�� 2��
���룺n = 2
�����1
���ͣ����ݹ���nums[0]��nums[1] �� nums[2] ֮�е����ֵ�� 1
ʾ�� 3��
���룺n = 3
�����2
���ͣ����ݹ���nums[0]��nums[1]��nums[2] �� nums[3] ֮�е����ֵ�� 2
��ʾ��
0 <= n <= 100
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        int ret = 0;
        map<int, int> m;
        m[0] = 0, m[1] = 1;
        for (int i = 0; i <= n; i++)
        {
            m[2 * i] = max(m[2 * i], m[i]);
            m[2 * i + 1] = max(m[2 * i + 1], m[i] + m[i + 1]);
            ret = max(ret, m[i]);
        }
        return ret;
    }
};
// map��¼��ֹԽ��

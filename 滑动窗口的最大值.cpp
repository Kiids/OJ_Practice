/*
����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ��
ʾ��:
����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
���: [3,3,5,5,6,7] 
����: 
  �������ڵ�λ��                ���ֵ
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
��ʾ��
����Լ��� k ������Ч�ģ����������鲻Ϊ�յ�����£�1 �� k �� ��������Ĵ�С��
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int max;
        for (int i = 0, j = k - 1; j >= 0 && j < nums.size(); j++)
        {
            if (i == 0 || max == nums[i - 1])
            {
                max = nums[i];
                for (int t = j; t > i; t--)
                {
                    if (max < nums[t])
                        max = nums[t];
                }
            }
            else
            {
                if (nums[j] > max)
                    max = nums[j];
            }
            ret.push_back(max);
            i++;
        }
        return ret;
    }
};

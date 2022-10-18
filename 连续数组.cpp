/*
����һ������������ nums , �ҵ�������ͬ������ 0 �� 1 ������������飬�����ظ�������ĳ��ȡ�
ʾ�� 1:
����: nums = [0,1]
���: 2
˵��: [0, 1] �Ǿ�����ͬ���� 0 �� 1 ������������顣
ʾ�� 2:
����: nums = [0,1,0]
���: 2
˵��: [0, 1] (�� [1, 0]) �Ǿ�����ͬ����0��1������������顣
��ʾ��
1 <= nums.length <= 10^5
nums[i] ���� 0 ���� 1
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> mp;
        int counter = 0;
        mp[counter] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num == 1)
                counter++;
            else
                counter--;
            if (mp.count(counter))
            {
                int prevIndex = mp[counter];
                maxLength = max(maxLength, i - prevIndex);
            }
            else
                mp[counter] = i;
        }
        return maxLength;
    }
};

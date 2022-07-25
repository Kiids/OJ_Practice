/*
����һ���±�� 0 ��ʼ���������� nums �������ҵ� ����� ���м�λ�� middleIndex ��Ҳ�������п����м�λ���±���С��һ������
�м�λ�� middleIndex ������ nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] �������±ꡣ
��� middleIndex == 0 ����߲��ֵĺͶ���Ϊ 0 �����Ƶģ���� middleIndex == nums.length - 1 ���ұ߲��ֵĺͶ���Ϊ 0 ��
���㷵�������������� ����� �� middleIndex ������������������м�λ�ã����㷵�� -1 ��
ʾ�� 1��
���룺nums = [2,3,-1,8,4]
�����3
���ͣ�
�±� 3 ֮ǰ�����ֺ�Ϊ��2 + 3 + -1 = 4
�±� 3 ֮������ֺ�Ϊ��4 = 4
ʾ�� 2��
���룺nums = [1,-1,4]
�����2
���ͣ�
�±� 2 ֮ǰ�����ֺ�Ϊ��1 + -1 = 0
�±� 2 ֮������ֺ�Ϊ��0
ʾ�� 3��
���룺nums = [2,5]
�����-1
���ͣ�
�����ڷ���Ҫ��� middleIndex ��
ʾ�� 4��
���룺nums = [1]
�����0
���ͣ�
�±� 0 ֮ǰ�����ֺ�Ϊ��0
�±� 0 ֮������ֺ�Ϊ��0
��ʾ��
1 <= nums.length <= 100
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> sum{0};
        for (auto& e : nums) 
            sum.push_back(sum.back() + e);
        for (int i = 1; i < sum.size(); i++)
        {
            int left = 0, right = 0;
            left += sum[i - 1];
            right += sum.back() - sum[i];
            if (left == right)
                return i - 1;
        }
        return -1;
    }
};

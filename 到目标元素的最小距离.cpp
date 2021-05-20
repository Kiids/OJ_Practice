/*
����һ���������� nums ���±� �� 0 ��ʼ �������Լ��������� target �� start �������ҳ�һ���±� i ������ nums[i] == target �� abs(i - start) ��С�� ��ע�⣺abs(x) ��ʾ x �ľ���ֵ��
���� abs(i - start) ��
��Ŀ���ݱ�֤ target ������ nums �С�
ʾ�� 1��
���룺nums = [1,2,3,4,5], target = 5, start = 3
�����1
���ͣ�nums[4] = 5 ��Ψһһ������ target ��ֵ�����Դ��� abs(4 - 3) = 1 ��
ʾ�� 2��
���룺nums = [1], target = 1, start = 0
�����0
���ͣ�nums[0] = 1 ��Ψһһ������ target ��ֵ�����Դ��� abs(0 - 0) = 0 ��
ʾ�� 3��
���룺nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
�����0
���ͣ�nums �е�ÿ��ֵ���� 1 ���� nums[0] ʹ abs(i - start) �Ľ��������С�������Դ��� abs(0 - 0) = 0 ��
��ʾ��
1 <= nums.length <= 1000
1 <= nums[i] <= 104
0 <= start < nums.length
target ������ nums ��
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                if (abs(i - start) < min)
                    min = abs(i - start);
        return min;
    }
};

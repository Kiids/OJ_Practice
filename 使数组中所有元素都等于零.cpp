/*
����һ���Ǹ��������� nums ����һ�������У�����룺
ѡ��һ�������� x ��x ��ҪС�ڻ���� nums �� ��С �� ���� Ԫ�ء�
nums �е�ÿ������������ȥ x��
����ʹ nums ������Ԫ�ض����� 0 ��Ҫ�� ���� ��������
ʾ�� 1��
���룺nums = [1,5,0,3,5]
�����3
���ͣ�
��һ��������ѡ�� x = 1 ��֮�� nums = [0,4,0,2,4] ��
�ڶ���������ѡ�� x = 2 ��֮�� nums = [0,2,0,0,2] ��
������������ѡ�� x = 2 ��֮�� nums = [0,0,0,0,0] ��
ʾ�� 2��
���룺nums = [0]
�����0
���ͣ�nums �е�ÿ��Ԫ�ض��Ѿ��� 0 �����Բ���Ҫִ���κβ�����
��ʾ��
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
               m[nums[i]]++;
               if (m[nums[i]] == 1)
                   v.push_back(nums[i]);
            }
        }
        return v.size();
    }
};

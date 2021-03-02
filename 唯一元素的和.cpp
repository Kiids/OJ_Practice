/*
����һ���������� nums ��������ΨһԪ������Щֻ���� ǡ��һ�� ��Ԫ�ء�
���㷵�� nums ��ΨһԪ�ص� �� ��
ʾ�� 1��
���룺nums = [1,2,3,2]
�����4
���ͣ�ΨһԪ��Ϊ [1,3] ����Ϊ 4 ��
ʾ�� 2��
���룺nums = [1,1,1,1,1]
�����0
���ͣ�û��ΨһԪ�أ���Ϊ 0 ��
ʾ�� 3 ��
���룺nums = [1,2,3,4,5]
�����15
���ͣ�ΨһԪ��Ϊ [1,2,3,4,5] ����Ϊ 15 ��
��ʾ��
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> m;
        for (auto& n : nums)
        {
            m[n]++;
            ret += (m[n] == 1) ? n : 0;
            ret -= (m[n] == 2) ? n : 0;
        }
        return ret;
    }
};

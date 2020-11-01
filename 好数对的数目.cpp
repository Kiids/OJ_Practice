/*
����һ���������� nums ��
���һ������ (i,j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��
���غ����Ե���Ŀ��
ʾ�� 1��
���룺nums = [1,2,3,1,1,3]
�����4
���ͣ��� 4 ������ԣ��ֱ��� (0,3), (0,4), (3,4), (2,5) ���±�� 0 ��ʼ
ʾ�� 2��
���룺nums = [1,1,1,1]
�����6
���ͣ������е�ÿ�����ֶ��Ǻ�����
ʾ�� 3��
���룺nums = [1,2,3]
�����0
��ʾ��
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0;
        for (auto e : nums)
        {
            if (m.find(e) != m.end())
                ret += m[e];
            m[e]++;
        }
        return ret;
    }
};

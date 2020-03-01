/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ���
ʾ��:
����: nums = [1,2,3]
���:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int size = 1 << nums.size();  // 2^n���Ӽ�
        for (int i = 0; i < size; i++)
        {
            vector<int> v;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << (j%32)))  // %32Ϊ�˽��Line 11: Char 28: runtime error: shift exponent 32 is too large for 32-bit type 'int' (solution.cpp)
                    v.push_back(nums[j]);
                
            }
            ret.push_back(v);
        }
        return ret;
    }
};

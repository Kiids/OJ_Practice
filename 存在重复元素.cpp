/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
ʾ�� 1:
����: [1,2,3,1]
���: true
ʾ�� 2:
����: [1,2,3,4]
���: false
ʾ�� 3:
����: [1,1,1,3,3,4,3,2,4,2]
���: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*for (size_t i = 0; i < nums.size() - 1; i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return true;
        }
        return false;  �ᳬ��ʱ������*/
        /*std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
        ִ�г��� Line 923: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)*/
        unordered_map<int, int>count;
		for (auto &e : nums)
			count[e]++;
		/*for (auto &e : count) {
			if (e.second > 1) {
				return 1;
			}
		}
		return 0;*/
		return count.size() != nums.size();
    }
};

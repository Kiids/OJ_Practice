/*
����һ�����г̳��ȱ���ѹ���������б� nums ��
����ÿ�����ڵ�����Ԫ�� [freq, val] = [nums[2*i], nums[2*i+1]] ������ i >= 0 ����ÿһ�Զ���ʾ��ѹ�����б����� freq ��ֵΪ val ��Ԫ�أ�����Ҫ�����������������б������ɽ�ѹ����б�
���㷵�ؽ�ѹ����б�
ʾ����
���룺nums = [1,2,3,4]
�����[2,4,4,4]
���ͣ���һ�� [1,2] ������ 2 �ĳ���Ƶ��Ϊ 1�������������� [2]��
�ڶ��� [3,4] ������ 4 �ĳ���Ƶ��Ϊ 3�������������� [4,4,4]��
������Ǵ�����һ�� [2] + [4,4,4] = [2,4,4,4]��
ʾ�� 2��
���룺nums = [1,1,2,3]
�����[1,3,3]
��ʾ��
2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i += 2)
            for (int j = 0; j < nums[i]; j++)
                ret.push_back(nums[i + 1]);
        return ret;
    }
};

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; 2 * i < nums.size(); i ++) 
            res.insert(res.end(), nums[2 * i], nums[2 * i + 1]);
        return res;
    }
};

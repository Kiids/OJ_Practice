/*
��������Ϊ 2n ������, ��������ǽ���Щ���ֳ� n ��, ���� (a1, b1), (a2, b2), ..., (an, bn) ��ʹ�ô�1 �� n �� min(ai, bi) �ܺ����
ʾ�� 1:
����: [1,4,3,2]
���: 4
����: n ���� 2, ����ܺ�Ϊ 4 = min(1, 2) + min(3, 4).
��ʾ:
n ��������,��Χ�� [1, 10000].
�����е�Ԫ�ط�Χ�� [-10000, 10000].
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0; i < nums.size(); i += 2)
            ret += nums[i];

        return ret;
    }
};

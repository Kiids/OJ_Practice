/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
ʾ��:
����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:
������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
            if (nums[fastIndex] != 0)
                nums[slowIndex++] = nums[fastIndex];
        for (int i = slowIndex; i < nums.size(); i++)
            nums[i] = 0;
    }
};

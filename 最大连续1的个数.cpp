/*
����һ�����������飬 ���������������1�ĸ�����
ʾ�� 1:
����: [1,1,0,1,1,1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
ע�⣺
���������ֻ���� 0 ��1��
��������ĳ��������������Ҳ����� 10,000��
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, num = 0;
        for (auto i : nums)
        {
            if (i == 1)
                num++;
            else
                num = 0;
            max = max > num ? max : num;
        }
        return max;
    }
};

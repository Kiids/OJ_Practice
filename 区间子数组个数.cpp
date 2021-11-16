/*
����һ��Ԫ�ض���������������A �������� L �Լ� R (L <= R)��
���������ǿ����������Ԫ��������ڵ���L С�ڵ���R�������������
���� :
����: 
A = [2, 1, 4, 3]
L = 2
R = 3
���: 3
����: ����������������: [2], [2, 1], [3].
ע��:
L, R  �� A[i] ������������Χ�� [0, 10^9]��
���� A �ĳ��ȷ�Χ��[1, 50000]��
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastR = -1, lastD = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > right)
            {
                lastR = i;
                lastD = 0;
            }
            else if (nums[i] < left)
                ret += lastD;
            else
            {
                lastD = i - lastR;
                ret += lastD;
            }
        }
        return ret;
    }
};

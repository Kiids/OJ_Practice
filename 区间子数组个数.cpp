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
            if (nums[i] > right)      // �������������¼��� 
            {
                lastR = i;
                lastD = 0;
            }
            else if (nums[i] < left)  // ���� ret ���� 
                ret += lastD;
            else
            {
                lastD = i - lastR;    // ���ȼ����� i �����������
                ret += lastD;
            }
        }
        return ret;
    }
};

// ��̬�滮
// d[i]��ʾ����i�����������������������ĸ���
// ��ʼ��d[i]����0
// nums[i] > right: �����㣬��ôd[i]=0,���Ҽ�¼lastRΪ��һ������R�ĵ����
// nums[i] < left�������ܳ�Ϊ�������㣬���������� d[i-1]
// nums[i] �ڷ�Χ�ڣ����ĳ��Ⱦ��� i- lastR��Ҳ���ǰ���i��������ĸ���
// ���sum_overi (d[i])
// �Ż�
// ֻ������ lastR��LastD �� �ۼƵ��������


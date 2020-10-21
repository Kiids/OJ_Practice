/*
����һ���������� A��ֻ�п��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false��
��ʽ�ϣ���������ҳ����� i+1 < j ������ A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1] �Ϳ��Խ��������ȷ֡�
ʾ�� 1��
���룺[0,2,1,-6,6,-7,9,1,2,0,1]
�����true
���ͣ�0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
ʾ�� 2��
���룺[0,2,1,-6,6,7,9,-1,2,0,1]
�����false
ʾ�� 3��
���룺[3,3,6,5,-2,2,5,1,-9,4]
�����true
���ͣ�3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
��ʾ��
3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0)
            return false;
        
        int count = 0, bufenSum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            bufenSum += A[i];
            if (bufenSum == sum / 3)
            {
                count ++;
                bufenSum = 0;
            }
            if (count == 3)
                return true;
        }
        return false;
    }
};

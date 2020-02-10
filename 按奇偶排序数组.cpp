/*
����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�
����Է���������������κ�������Ϊ�𰸡�
ʾ����
���룺[3,1,2,4]
�����[2,4,3,1]
��� [4,2,3,1]��[2,4,1,3] �� [4,2,1,3] Ҳ�ᱻ���ܡ�
��ʾ��
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l < r)
        {
            while (A[l] % 2 == 0)
            {
                if (l == r - 1)
                    return A;
                l++;
            }
            while (A[r] % 2 != 0)
            {
                if (r == l + 1)
                    return A;
                r--;
            }
            swap(A[l], A[r]);
        }
        return A;
    }
};

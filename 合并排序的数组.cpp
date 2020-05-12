/*
������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A ������
��ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n��
ʾ��:
����:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
���: [1,2,2,3,5,6]
˵��:
A.length == n + m
*/

// ����˫ָ�� ԭ���޸� ʱ�临�Ӷȣ�O(m+n)O(m+n) �ռ临�Ӷȣ�O(1)O(1)
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a = m - 1, b = n - 1, last = m + n - 1, cur;
        while (a >= 0 || b >= 0)
        {
            if (a == -1)
                cur = B[b--];
            else if (b == -1)
                cur = A[a--];
            else if (A[a] > B[b])
                cur = A[a--];
            else
                cur = B[b--];
            A[last--] = cur;
        }
    }
};

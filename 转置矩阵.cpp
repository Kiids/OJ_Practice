/*
����һ������ A�� ���� A ��ת�þ���
�����ת����ָ����������Խ��߷�ת���������������������������
ʾ�� 1��
���룺[[1,2,3],[4,5,6],[7,8,9]]
�����[[1,4,7],[2,5,8],[3,6,9]]
ʾ�� 2��
���룺[[1,2,3],[4,5,6]]
�����[[1,4],[2,5],[3,6]]
��ʾ��
1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ret(A[0].size(), vector<int>(A.size(), 0));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++)
                ret[j][i] = A[i][j];
        return ret;
    }
};

/*
����M��N����ÿһ�С�ÿһ�ж����������У����д�����ҳ�ĳԪ�ء�
ʾ��:
���о��� matrix ���£�
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target = 5������ true��
���� target = 20������ false��
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        // ���Ͻ�
        int row = 0;
        int col = matrix.at(0).size() - 1;

        // ���½�
        int end_row = matrix.size() - 1;
        int end_col = 0;

        while (row <= end_row && col >= end_col)
        {
            if (matrix.at(row).at(col) == target)
                return true;
            else if(target < matrix.at(row).at(col)) // ��߲�����
                col--;
            else if (target > matrix.at(row).at(col)) // �±߲�����
                row++;
        }
        return false;
    }
};

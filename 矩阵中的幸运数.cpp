/*
����һ�� m * n �ľ��󣬾����е����� ������ͬ �����㰴 ���� ˳�򷵻ؾ����е�������������
��������ָ����������ͬʱ��������������Ԫ�أ�
��ͬһ�е�����Ԫ������С
��ͬһ�е�����Ԫ�������
ʾ�� 1��
���룺matrix = [[3,7,8],[9,11,13],[15,16,17]]
�����[15]
���ͣ�15 ��Ψһ������������Ϊ�������������е���Сֵ��Ҳ���������е����ֵ��
ʾ�� 2��
���룺matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
�����[12]
���ͣ�12 ��Ψһ������������Ϊ�������������е���Сֵ��Ҳ���������е����ֵ��
ʾ�� 3��
���룺matrix = [[7,8],[1,2]]
�����[7]
��ʾ��
m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5
�����е�����Ԫ�ض��ǲ�ͬ��
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ret;
        for (int i = 0; i < matrix.size(); i++)
        {
            int min = matrix[i][0];
            int index = 0;

            //�ҳ�һ������С������������ֵ�����±�
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                    index = j;
                }
            }

            //�ж����Ƿ��Ǹ��е����ֵ
            int flag = 1;
            for (int m = 0; m < matrix.size(); m++)
            {
                if (matrix[m][index] > min)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ret.push_back(min);
        }
        return ret;
    }
};

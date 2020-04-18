/*
����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
ʾ�� 1��
���룺target = 9
�����[[2,3,4],[4,5]]
ʾ�� 2��
���룺target = 15
�����[[1,2,3,4,5],[4,5,6],[7,8]]
���ƣ�
1 <= target <= 10^5

*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // ��������
        int i = 1, j = 1, sum = 0;
        vector<vector<int>> ret;

        while (i <= target / 2)
        {
            if (sum < target)  // �ұ߽������ƶ�
            {
                sum += j;
                j++;
            }
            else if (sum > target)  // ��߽������ƶ�
            {
                sum -= i;
                i++;
            }
            else
            {
                vector<int> v;
                for (int k = i; k < j; k++)
                    v.push_back(k);
                ret.push_back(v);

                // ��߽������ƶ�
                sum -= i;
                i++;
            }
        }
        return ret;
    }
};


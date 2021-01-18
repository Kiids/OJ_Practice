/*
�� n λ�û��μӻ�����ǵ� ID �� 0 �� n - 1��ÿλ�û��� ǡ�� ����ĳһ�û��顣����һ������Ϊ n ������ groupSizes�����а���ÿλ�û��������û���Ĵ�С�����㷵���û�������������ڵ��û����Լ�ÿ�������û��� ID����
������κ�˳�򷵻ؽ��������ID ��˳��Ҳ�������ơ����⣬��Ŀ���������ݱ�֤���ٴ���һ�ֽ��������
ʾ�� 1��
���룺groupSizes = [3,3,3,3,3,1,3]
�����[[5],[0,1,2],[3,4,6]]
���ͣ� 
�������ܵĽ�������� [[2,1,6],[5],[0,4,3]] �� [[5],[0,6,2],[4,3,1]]��
ʾ�� 2��
���룺groupSizes = [2,1,3,3,3,2]
�����[[1],[0,5],[2,3,4]]
��ʾ��
groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> v(500), ret;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            v[groupSizes[i]].emplace_back(i);
            if (v[groupSizes[i]].size() == groupSizes[i])
            {
                ret.emplace_back(v[groupSizes[i]]);
                v[groupSizes[i]].clear();
            }
        }
        return ret;
    }
};

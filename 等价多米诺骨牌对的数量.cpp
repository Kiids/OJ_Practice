/*
����һ����һЩ����ŵ������ɵ��б� dominoes��
�������ĳһ�Ŷ���ŵ���ƿ���ͨ����ת 0 �Ȼ� 180 �ȵõ���һ�Ŷ���ŵ���ƣ����Ǿ���Ϊ���������ǵȼ۵ġ�
��ʽ�ϣ�dominoes[i] = [a, b] �� dominoes[j] = [c, d] �ȼ۵�ǰ���� a==c �� b==d������ a==d �� b==c��
�� 0 <= i < j < dominoes.length ��ǰ���£��ҳ����� dominoes[i] �� dominoes[j] �ȼ۵Ĺ��ƶ� (i, j) ��������
ʾ����
���룺dominoes = [[1,2],[2,1],[3,4],[5,6]]
�����1
��ʾ��
1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ret = 0;
        int nums[10][10]{0};
        for (auto d : dominoes)
        {   
            ret += nums[d[0]][d[1]];
            if (d[0] != d[1])
                ret += nums[d[1]][d[0]];
            nums[d[0]][d[1]]++;
        }
        return ret;
    }
};

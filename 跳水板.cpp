/*
������ʹ��һ��ľ�彨����ˮ�塣���������͵�ľ�壬���г��Ƚ϶̵�ľ�峤��Ϊshorter�����Ƚϳ���ľ�峤��Ϊlonger�����������ʹ��k��ľ�塣��дһ��������������ˮ�����п��ܵĳ��ȡ�
���صĳ�����Ҫ��С�������С�
ʾ����
���룺
shorter = 1
longer = 2
k = 3
����� {3,4,5,6}
��ʾ��
0 < shorter <= longer
0 <= k <= 100000
*/

// �����һ������Ϊ shorter * k ������Ϊ longer - shorter �������� longer * k �ĵȲ����� 
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ret;
        if (k == 0)
            return ret;
        if (shorter == longer)
            return vector<int>(1, k * shorter);
        
        int min = shorter * k;
        int max = longer * k;
        while (min < max + 1)
        {
            ret.push_back(min);
            min += longer - shorter;
        }
        return ret;
    }
};

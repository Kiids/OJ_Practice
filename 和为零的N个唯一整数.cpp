/*
����һ������ n�����㷵�� ���� һ���� n �� ������ͬ ��������ɵ����飬������ n ������Ӻ�Ϊ 0 ��
ʾ�� 1��
���룺n = 5
�����[-7,-1,1,3,4]
���ͣ���Щ����Ҳ����ȷ�� [-5,-1,1,2,3]��[-3,-1,2,-2,4]��
ʾ�� 2��
���룺n = 3
�����[-1,0,1]
ʾ�� 3��
���룺n = 1
�����[0]
��ʾ��
1 <= n <= 1000
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        int count = n / 2;
        while (count)
        {
            ret.push_back(count);
            ret.push_back(-count);
            count--;
        }
        if (n % 2 == 1)
            ret.push_back(0);
        return ret;
    }
};

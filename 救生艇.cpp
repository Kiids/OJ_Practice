/*
�� i ���˵�����Ϊ people[i]��ÿ�Ҵ����Գ��ص��������Ϊ limit��
ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit��
�����ص�ÿһ�����������С������(��֤ÿ���˶��ܱ�����)��
ʾ�� 1��
���룺people = [1,2], limit = 3
�����1
���ͣ�1 �Ҵ��� (1, 2)
ʾ�� 2��
���룺people = [3,2,2,1], limit = 3
�����3
���ͣ�3 �Ҵ��ֱ��� (1, 2), (2) �� (3)
ʾ�� 3��
���룺people = [3,5,3,4], limit = 5
�����4
���ͣ�4 �Ҵ��ֱ��� (3), (3), (4), (5)
��ʾ��
1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ret = 0;
        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
            {
                ret++;
                l++;
                r--;
            }
            else
            {
                ret++;
                r--;
            }
        }
        return ret;
    }
};

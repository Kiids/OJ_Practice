/*
Alice ������һ�ҹ�˾�������ô�¥�Ĳ���¥����Ϊ�칫�ռ䡣Alice ������һЩ¥����Ϊ ����¥�� �������ڷ��ɡ�
������������ bottom �� top ����ʾ Alice �����˴� bottom �� top���� bottom �� top ���ڣ�������¥�㡣�����һ���������� special ������ special[i] ��ʾ? Alice ָ�����ڷ��ɵ�����¥�㡣
���ز�������¥��� ��� ����¥������
ʾ�� 1��
���룺bottom = 2, top = 9, special = [4,6]
�����3
���ͣ������г����ǲ�������¥�������¥�㷶Χ��
- (2, 3) ��¥����Ϊ 2 ��
- (5, 5) ��¥����Ϊ 1 ��
- (7, 9) ��¥����Ϊ 3 ��
��ˣ������������¥���� 3 ��
ʾ�� 2��
���룺bottom = 6, top = 8, special = [7,6,8]
�����0
���ͣ�ÿ��¥�����滮Ϊ����¥�㣬���Է��� 0 ��
��ʾ
1 <= special.length <= 10^5
1 <= bottom <= special[i] <= top <= 10^9
special �е�����ֵ ������ͬ
*/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ret = 0;
        for (int i = 1; i < special.size(); i++)
            ret = max(ret, special[i] - special[i - 1] - 1); 
        ret = max(special[0] - bottom, max(top - special[special.size() - 1], ret));
        return ret;
    }
};

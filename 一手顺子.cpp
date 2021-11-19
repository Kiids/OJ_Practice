/*
����˿��һ�֣�hand������������������ơ� 
������������������г��飬ʹ��ÿ����Ĵ�С���� W������ W ������������ɡ�
�����������ɷ���ͷ��� true�����򷵻� false��
ʾ�� 1��
���룺hand = [1,2,3,6,2,3,4,7,8], W = 3
�����true
���ͣ�����˿�����ƿ��Ա���������Ϊ [1,2,3]��[2,3,4]��[6,7,8]��
ʾ�� 2��
���룺hand = [1,2,3,4,5], W = 4
�����false
���ͣ�����˿�������޷����������гɼ�����СΪ 4 ���顣
��ʾ��
1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for (int i = 0; i < hand.size(); i++)
            m[hand[i]]++;
        while (m.empty() == false)
        {
            auto a = m.begin()->first;
            for (int i = a, cnt = 0; cnt < groupSize; i++, cnt++)
            {
                if (m.count(i) == 0)
                    return false;
                m[i]--;
                if (m[i] == 0)
                    m.erase(i);
            }
        }
        return true;
    }
};

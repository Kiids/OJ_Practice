/*
����һ���ƣ�ÿ�����϶�д��һ��������
��ʱ������Ҫѡ��һ������ X��ʹ���ǿ��Խ������ư���������ֳ� 1 �������飺
ÿ�鶼�� X ���ơ�
�������е����϶�д����ͬ��������
�������ѡ�� X >= 2 ʱ���� true��
ʾ�� 1��
���룺[1,2,3,4,4,3,2,1]
�����true
���ͣ����еķ����� [1,1]��[2,2]��[3,3]��[4,4]
ʾ�� 2��
���룺[1,1,1,2,2,2,3,3]
�����false
���ͣ�û������Ҫ��ķ��顣
ʾ�� 3��
���룺[1]
�����false
���ͣ�û������Ҫ��ķ��顣
ʾ�� 4��
���룺[1,1]
�����true
���ͣ����еķ����� [1,1]
ʾ�� 5��
���룺[1,1,2,2,2,2]
�����true
���ͣ����еķ����� [1,1]��[2,2]��[2,2]
��ʾ��
1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        vector<int> v;
        for (auto e : deck)
            m[e] += 1;
        for (auto e : m)
            v.push_back(e.second);
        sort(v.begin(), v.end());

        for (int i = 2; i <= v[0]; i++)
        {
            int flag = 1;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] % i != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                return true;
        }
        return false;
    }
};

// ��ϣ��ͳ�ƴ��� & �ж����Լ���Ƿ���ڵ��� 2

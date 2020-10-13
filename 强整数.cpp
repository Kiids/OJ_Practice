/*
�������������� x �� y�����ĳһ�������� x^i + y^j���������� i >= 0 �� j >= 0����ô������Ϊ��������һ��ǿ������
����ֵС�ڻ���� bound ������ǿ������ɵ��б�
����԰��κ�˳�򷵻ش𰸡�����Ļش��У�ÿ��ֵ������һ�Ρ�
ʾ�� 1��
���룺x = 2, y = 3, bound = 10
�����[2,3,4,5,7,9,10]
���ͣ� 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
ʾ�� 2��
���룺x = 3, y = 5, bound = 15
�����[2,4,6,8,10,14]
��ʾ��
1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 0; ; i++)
        {
            int newx = (int)pow(x, i);
            if (newx >= bound)
                break;
            for (int j = 0; ; j++)
            {
                int newy = (int)pow(y, j);
                if (newx + newy > bound)
                    break;
                s.insert(newx + newy);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(s.begin(), s.end());
    }
};

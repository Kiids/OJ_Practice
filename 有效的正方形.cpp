/*
����2D�ռ����ĸ�������� p1, p2, p3 �� p4��������ĸ��㹹��һ�������Σ��򷵻� true ��
������� pi ��ʾΪ [xi, yi] ������ ���� ���κ�˳������ġ�
һ�� ��Ч�������� �������ȱߺ��ĸ��Ƚ�(90�Ƚ�)��
ʾ�� 1:
����: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
���: True
ʾ�� 2:
���룺p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
�����false
ʾ�� 3:
���룺p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
�����true
��ʾ:
p1.length == p2.length == p3.length == p4.length == 2
-10^4 <= xi, yi <= 10^4
*/

class Solution {
    int getLen(vector<int>& x, vector<int>& y)
    {
        return pow(y[0] - x[0], 2) + pow(y[1] - x[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> lens;
        lens.resize(6, 0);
        lens[0] = getLen(p1, p2);
        lens[1] = getLen(p1, p3);
        lens[2] = getLen(p1, p4);
        lens[3] = getLen(p2, p4);
        lens[4] = getLen(p2, p3);
        lens[5] = getLen(p3, p4);
        set<int> s;
        for (int i = 0; i < 6; i++)
        {
            if (lens[i] == 0)
                return false;
            s.insert(lens[i]);
        }
        return s.size() == 2 ? true : false;
    }
};

//�������е㵽������ĳ���
//�����������ߣ������Խ��ߣ��ߺͱ���ȣ��Խ��ߺͶԽ�����ȣ����ǳ�Ҫ����
//����set�����жϣ�����������Σ���ôsetֻ��������Ч����


/*
��������һ�����޴�С�� XY ����ƽ�������ߣ��ӵ� (0, 0) ����ʼ���������򱱷����û����˿��Խ��������������͵����� commands ��
-2 ������ת 90 ��
-1 ������ת 90 ��
1 <= x <= 9 ����ǰ�ƶ� x ����λ����
����������һЩ���ӱ���Ϊ�ϰ��� obstacles ���� i ���ϰ���λ�������  obstacles[i] = (xi, yi) ��
�������޷��ߵ��ϰ����ϣ�������ͣ�����ϰ����ǰһ�����񷽿��ϣ�����Ȼ���Լ������Խ��и�·�ߵ����ಿ�֡�
���ش�ԭ�㵽���������о�����·���㣨����Ϊ�����������ŷʽ�����ƽ�����������������Ϊ 5 ���򷵻� 25 ��
ע�⣺
����ʾ +Y ����
����ʾ +X ����
�ϱ�ʾ -Y ����
����ʾ -X ����
ʾ�� 1��
���룺commands = [4,-1,3], obstacles = []
�����25
���ͣ�
�����˿�ʼλ�� (0, 0)��
1. ���ƶ� 4 ����λ������ (0, 4)
2. ��ת
3. ���ƶ� 3 ����λ������ (3, 4)
����ԭ����Զ���� (3, 4) ������Ϊ 32 + 42 = 25
ʾ��?2��
���룺commands = [4,-1,4,-2,4], obstacles = [[2,4]]
�����65
���ͣ������˿�ʼλ�� (0, 0)��
1. ���ƶ� 4 ����λ������ (0, 4)
2. ��ת
3. ���ƶ� 1 ����λ��Ȼ��λ�� (2, 4) ���ϰ����赲��������ͣ�� (1, 4)
4. ��ת
5. ���� 4 ����λ������ (1, 8)
����ԭ����Զ���� (1, 8) ������Ϊ 12 + 82 = 65
��ʾ��
1 <= commands.length <= 10^4
commands[i] is one of the values in the list [-2,-1,1,2,3,4,5,6,7,8,9].
0 <= obstacles.length <= 10^4
-3 * 10^4 <= xi, yi <= 3 * 10^4
�𰸱�֤С�� 2^31
*/

class Solution {
public:
    vector<pair<int, int>> v = {{0,1}, {-1,0}, {0,-1}, {1,0}};  // �ĸ����� 
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction = 0, x = 0, y = 0, ret = 0;
        set<pair<int, int>> obset;
        for (auto &e : obstacles)
            obset.insert({e[0], e[1]});
        for (auto &command : commands)
        {
            if (command == -1)
                direction--;
            else if (command == -2)
                direction++;
            else
            {
                int cur = (direction + 400000) % 4;
                int len = command;
                while (len)
                {
                    int nxt_x = x + v[cur].first;
                    int nxt_y = y + v[cur].second;
                    if (!obset.count({nxt_x, nxt_y}))
                    {
                        x = nxt_x;
                        y = nxt_y;
                    }
                    len--;
                    ret = max(ret, x * x + y * y);
                }
            }
        }
        return ret;
    }
};

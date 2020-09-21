/*
����һ���ַ��� path������ path[i] ��ֵ������ 'N'��'S'��'E' ���� 'W'���ֱ��ʾ�򱱡����ϡ��򶫡������ƶ�һ����λ��
�����˴Ӷ�άƽ���ϵ�ԭ�� (0, 0) ����ʼ�������� path ��ָʾ��·�����ߡ�
���·�����κ�λ���ϳ����ཻ�������Ҳ�����ߵ�֮ǰ�Ѿ��߹���λ�ã��뷵�� True �����򣬷��� False ��
ʾ�� 1��
���룺path = "NES"
�����false 
���ͣ���·��û�����κ�λ���ཻ��
ʾ�� 2��
���룺path = "NESWW"
�����true
���ͣ���·������ԭ�����Ρ�
��ʾ��
1 <= path.length <= 10^4
path ���� {'N', 'S', 'E', 'W} �е��ַ����
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s;
        int x = 0, y = 0;
        s.insert({ 0, 0 });
        for (auto& e : path)
        {
            if (e == 'N')
                y++;
            if (e == 'S')
                y--;
            if (e == 'E')
                x++;
            if (e == 'W')
                x--;
            if (s.count({ x, y }))
                return true;
            s.insert({ x, y });
        }
        return false;
    }
};

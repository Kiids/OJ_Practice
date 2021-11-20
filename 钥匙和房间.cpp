/*
�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1�����ҷ����������һЩԿ����ʹ�������һ�����䡣
����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ������ N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣
������� 0 �ŷ�������������з��䶼����ס��
��������ɵ��ڷ���֮�������߶���
����ܽ���ÿ�����䷵�� true�����򷵻� false��
ʾ�� 1��
����: [[1],[2],[3],[]]
���: true
����:  
���Ǵ� 0 �ŷ��俪ʼ���õ�Կ�� 1��
֮������ȥ 1 �ŷ��䣬�õ�Կ�� 2��
Ȼ������ȥ 2 �ŷ��䣬�õ�Կ�� 3��
�������ȥ�� 3 �ŷ��䡣
���������ܹ�����ÿ�����䣬���Ƿ��� true��
ʾ�� 2��
���룺[[1,3],[3,0,1],[2],[0]]
�����false
���ͣ����ǲ��ܽ��� 2 �ŷ��䡣
��ʾ��
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
���з����е�Կ�������ܼƲ�����?3000��
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;  
        vector<int> v(rooms.size());
        q.push(0);
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                int curRoom = q.front();
                q.pop();
                if (v[curRoom])
                    continue;
                for (int nexRoom : rooms[curRoom])
                    q.push(nexRoom);
                v[curRoom] = 1;
            }
        }
        for (int i = 0; i < rooms.size(); i++)
            if (v[i] == 0)
                return false;
        return true;
    }
};

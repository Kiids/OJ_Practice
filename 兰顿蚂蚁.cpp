/*
һֻ���������ɰ�ɫ�ͺ�ɫ���񹹳ɵ����������ϡ���ʼʱ������ȫ�ף����������Ҳࡣÿ����һ��������ִ�����²�����
(1) ����ڰ�ɫ�����ϣ���ת�������ɫ������(˳ʱ��)ת 90 �ȣ�����ǰ�ƶ�һ����λ��
(2) ����ں�ɫ�����ϣ���ת�������ɫ������(��ʱ�뷽��)ת 90 �ȣ�����ǰ�ƶ�һ����λ��
��д������ģ������ִ�е�ǰ K �����������������յ�����
�����������ʾ��ÿ��Ԫ����һ���ַ��������������е�һ�У���ɫ������?'X'?��ʾ����ɫ������?'_'?��ʾ���������ڵ�λ����?'L', 'U', 'R', 'D'?��ʾ���ֱ��ʾ����?���ϡ��ҡ��� �ĳ���ֻ��Ҫ�����ܹ����������߹������з������С���Ρ�
ʾ�� 1:
����: 0
���: ["R"]
ʾ�� 2:
����: 2
���:
[
? "_X",
? "LX"
]
ʾ�� 3:
����: 5
���:
[
? "_U",
? "X_",
? "XX"
]
˵����
K <= 100000
*/

class Solution {
public:
    vector<string> printKMoves(int K) {
        // ����ģ��
        if (!K)
            return {"R"};
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // ��������
        string directions = "LURD";
        deque<deque<char>> map;
        map.push_back(deque<char>(1, '_')); // ��ʼ��

        int i = 0, j = 0, d = 2; // 0-4: ��������
        int col = 1;
        while (K --)
        {
            if (map[i][j] == '_')
            { // ��ת���ı䷽��
                map[i][j] = 'X';
                d = (d + 1) % 4;
            }
            else if (map[i][j] == 'X')
            { // ��ת���ı䷽��
                map[i][j] = '_';
                d = (d + 3) % 4;
            }

            i += dx[d], j += dy[d]; // ǰ��

            // ���µ�ͼ
            // ������
            if (i > (int)map.size() - 1)
                map.push_back(deque<char>(col, '_'));
            else if (i < 0)
                map.push_front(deque<char>(col, '_')), i ++;

            // ������
            if (j > col - 1)
            { // ��������һ��
                for (auto& x: map) x.push_back('_');
                col ++;
            }
            else if (j < 0)
            { // ǰ������һ��
                for (auto& x: map) x.push_front('_');
                j ++, col ++;
            }
        }
        map[i][j] = directions[d]; // �����յ��ﵥλ

        // �ռ�����
        vector<string> res;
        for (int i = 0; i < map.size(); i ++)
        {
            string ans = "";
            for (auto c: map[i])
                ans += c;
            res.push_back(ans);
        }
        return res;
    }
};

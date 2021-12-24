/*
���������� 0 �� 1 ��ɵľ��� matrix������ѡ�������������в���ת���ϵ� ÿ�� ��Ԫ�񡣷�ת�󣬵�Ԫ���ֵ�� 0 ��� 1�����ߴ� 1 ��Ϊ 0 ��
�ؾ���һЩ��ת��������֮������ֵ����ȵ����������
ʾ�� 1��
���룺[[0,1],[1,1]]
�����1
���ͣ������з�ת���� 1 ������ֵ����ȡ�
ʾ�� 2��
���룺[[0,1],[1,0]]
�����2
���ͣ���ת��һ�е�ֵ֮�������ж�����ȵ�ֵ��ɡ�
ʾ�� 3��
���룺[[0,0,0],[0,0,1],[1,1,0]]
�����2
���ͣ���תǰ���е�ֵ֮�󣬺���������ȵ�ֵ��ɡ�
��ʾ��
1 <= matrix.length <= 300
1 <= matrix[i].length <= 300
���� matrix[i].length �����
matrix[i][j] Ϊ 0 �� 1
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        for (auto row : matrix)
        {
            string mode = "";
            if (row[0] == 0)
                for (int x: row)
                    mode += ('0' + x);
            else
                for (int x: row)
                    mode += (x == 0 ? '1' : '0');
            m[mode] ++;
        }

        int ret = 0;
        for (auto [mode, freq] : m)
            ret = max(ret, freq);
        return ret;
    }
};

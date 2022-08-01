/*
����һ����ά�������� ranges ���������� left �� right ��ÿ�� ranges[i] = [starti, endi] ��ʾһ���� starti �� endi �� ������ ��
��������� [left, right] ��ÿ���������� ranges �� ����һ�� ���串�ǣ���ô���㷵�� true �����򷵻� false ��
��֪���� ranges[i] = [starti, endi] ��������� x ���� starti <= x <= endi ����ô���ǳ�����x �������ˡ�
ʾ�� 1��
���룺ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
�����true
���ͣ�2 �� 5 ��ÿ���������������ˣ�
- 2 ����һ�����串�ǡ�
- 3 �� 4 ���ڶ������串�ǡ�
- 5 �����������串�ǡ�
ʾ�� 2��
���룺ranges = [[1,10],[10,20]], left = 21, right = 21
�����false
���ͣ�21 û�б��κ�һ�����串�ǡ�
��ʾ��
1 <= ranges.length <= 50
1 <= starti <= endi <= 50
1 <= left <= right <= 50
*/

class Solution {
    bool m[100];
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (auto& e : ranges)
        {
            for (int i = e[0]; i <= e[1]; i++)
                m[i] = true;
        }
        for (int i = left; i <= right; i++)
            if (!m[i])
                return false;
        return true;
    }
};

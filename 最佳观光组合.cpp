/*
����һ������������ values������ values[i] ��ʾ�� i ���۹⾰������֣������������� i �� j ֮��� ���� Ϊ j - i��
һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ values[i] + values[j] + i - j ��Ҳ���Ǿ��������֮�� ��ȥ ��������֮��ľ��롣
����һ�Թ۹⾰����ȡ�õ���߷֡�
ʾ�� 1��
���룺values = [8,1,5,2,6]
�����11
���ͣ�i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
ʾ�� 2��
���룺values = [1,2]
�����2
��ʾ��
2 <= values.length <= 5 * 10^4
1 <= values[i] <= 1000
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int l = 0, ret = INT_MIN;
        for (int i = 0; i < values.size(); i++)
        {
            ret = max(ret, l + values[i] - i);  // �������������ֵ
            l = max(l, values[i] + i);          // ���� values[i] + i�����ֵ
        }
        return ret;
    }
};

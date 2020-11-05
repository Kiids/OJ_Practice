/*
����һ���������� arr �������е�ÿ������ ������ͬ ������һ�����������鹹�ɵ����� pieces�����е�����Ҳ ������ͬ �������� ����˳�� ���� pieces �е��������γ� arr �����ǣ������� ��ÿ������ pieces[i] �е�������������
����������� pieces �е������γ� arr ������ true �����򣬷��� false ��
ʾ�� 1��
���룺arr = [85], pieces = [[85]]
�����true
ʾ�� 2��
���룺arr = [15,88], pieces = [[88],[15]]
�����true
���ͣ��������� [15] �� [88]
ʾ�� 3��
���룺arr = [49,18,16], pieces = [[16,18,49]]
�����false
���ͣ��������������Ҳ������������ pieces[0]
ʾ�� 4��
���룺arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
�����true
���ͣ��������� [91]��[4,64] �� [78]
ʾ�� 5��
���룺arr = [1,3,5,7], pieces = [[2,4,6,8]]
�����false
��ʾ��
1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
arr �е����� ������ͬ
pieces �е����� ������ͬ��Ҳ����˵������� pieces ��ƽ����һά���飬�����е���������������ͬ��
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> m;
        for (int i = 0; i < pieces.size(); i++)
            m[pieces[i][0]] = i;

        for (int i = 0; i < arr.size(); )
        {
            if (m.find(arr[i]) == m.end())
                return false;
            auto& p = pieces[m[arr[i]]];
            for (int j = 0; j < p.size(); j++, i++)
                if (arr[i] != p[j])
                    return false;
        }
        return true;
    }
};

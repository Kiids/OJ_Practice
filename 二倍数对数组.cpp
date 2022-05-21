/*
����һ������Ϊż������������ arr��ֻ�ж� arr ���������������� ������ÿ�� 0 <= i < len(arr) / 2������ arr[2 * i + 1] = 2 * arr[2 * i]�� ʱ������ true�����򣬷��� false��
ʾ�� 1��
���룺arr = [3,1,3,6]
�����false
ʾ�� 2��
���룺arr = [2,1,2,6]
�����false
ʾ�� 3��
���룺arr = [4,-2,2,-4]
�����true
���ͣ������� [-2,-4] �� [2,4] ��������� [-2,-4,2,4] ���� [2,4,-2,-4]
��ʾ��
0 <= arr.length <= 3 * 10^4
arr.length ��ż��
-10^5 <= arr[i] <= 10^5
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        for (auto e: arr)
        {
            if (e % 2 == 0 && e > 0 && m[e / 2])
                m[e / 2]--;
            else if (e < 0 && m[e * 2])
                m[e * 2]--;
            else
                m[e]++;
        }

        for (auto e: m)
        {
            if (e.first == 0)
            {
                if (e.second % 2 == 0)
                    continue;
                return false;
            }
            if (e.second)
                return false;
        }
        return true;
    }
};

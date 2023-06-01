/*
����һ���������� arr ��һ������ k ��ͨ���ظ� k �����޸����顣
���磬���?arr = [1, 2] �� k = 3 ����ô�޸ĺ�����齫�� [1, 2, 1, 2, 1, 2] ��
�����޸ĺ�������е�����������֮�͡�ע�⣬�����鳤�ȿ����� 0������������������ܺ�Ҳ�� 0��
���� ������ܻ�ܴ���Ҫ���ص� 10^9 + 7 �� ģ ��
ʾ�� 1��
���룺arr = [1,2], k = 3
�����9
ʾ�� 2��
���룺arr = [1,-2,1], k = 5
�����2
ʾ�� 3��
���룺arr = [-1,-2], k = 7
�����0
��ʾ��
1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4
*/

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<long long> v(2 * arr.size());
        long long ret = 0, mod = 1e9+7, sum = 0, max_sum = 0, min = 0, n = arr.size();
        for (auto a: arr)
        {
            sum += a;
            max_sum = max_sum > a ? max_sum : a;
        }
        if (max_sum <= 0)
            return 0;
        
        v[0] = arr[0];
        ret = ret > arr[0] ? ret : arr[0];
        min = min < arr[0] ? min : arr[0];
        for (int i = 1; i < 2 * n; i++)
        {
            v[i] = v[i - 1] + arr[i % n];
            long long tmp = v[i] - min;
            ret = ret > tmp ? ret : tmp;;
            min = min < v[i] ? min : v[i];

            if (k == 1 && i == n - 1)
                return ret;
        }
        if (sum > 0)
            ret = (ret + sum * (k - 2)) % mod;
        return ret;
    }
};

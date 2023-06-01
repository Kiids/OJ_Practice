/*
给定一个整数数组 arr 和一个整数 k ，通过重复 k 次来修改数组。
例如，如果?arr = [1, 2] ， k = 3 ，那么修改后的数组将是 [1, 2, 1, 2, 1, 2] 。
返回修改后的数组中的最大的子数组之和。注意，子数组长度可以是 0，在这种情况下它的总和也是 0。
由于 结果可能会很大，需要返回的 10^9 + 7 的 模 。
示例 1：
输入：arr = [1,2], k = 3
输出：9
示例 2：
输入：arr = [1,-2,1], k = 5
输出：2
示例 3：
输入：arr = [-1,-2], k = 7
输出：0
提示：
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

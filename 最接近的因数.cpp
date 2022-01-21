/*
给你一个整数 num，请你找出同时满足下面全部要求的两个整数：
两数乘积等于  num + 1 或 num + 2
以绝对差进行度量，两数大小最接近
你可以按任意顺序返回这两个整数。
示例 1：
输入：num = 8
输出：[3,3]
解释：对于 num + 1 = 9，最接近的两个因数是 3 & 3；对于 num + 2 = 10, 最接近的两个因数是 2 & 5，因此返回 3 & 3 。
示例 2：
输入：num = 123
输出：[5,25]
示例 3：
输入：num = 999
输出：[40,25]
提示：
1 <= num <= 10^9
*/

class Solution {
    void Fun(int num, vector<int>& v)
    {
        for (int i = int(sqrt(num)); i > 0; i--)
        {
            if (num % i == 0)
            {
                if (abs(num / i - i) < abs(v[0] - v[1]))
                {
                    v[0] = num / i;
                    v[1] = i;
                }
            }
        }
    }
public:
    vector<int> closestDivisors(int num) {
        vector<int> v(2, 0);
        v[1] = 1e9;
        Fun(num + 1, v);
        Fun(num + 2, v);
        return v;
    }
};

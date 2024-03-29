/*
给定一个长度为 n 的整数数组 A 。
假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：
F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]。
计算F(0), F(1), ..., F(n-1)中的最大值。
注意:
可以认为 n 的值小于 10^5。
示例:
A = [4, 3, 2, 6]
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, pre = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            pre += i * nums[i];
        }
        int ret = pre;
        for (int i = 1; i < n; i++)
        {
            pre += sum - n * nums[n - i];
            ret = max(ret, pre);
        }
        return ret;
    }
};

// 找规律，递推 
// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
// sum = arr[0]+arr[1]+...+arr[n-1]
// F(k+1) = F(k) + sum - n*arr[n-k-1]
// f(0) = F(0)
// f(x) = F(x-1)+sum - n*(arr[n-x]) x: 1~n-1

// 公式F(1)和F(0)的关系：
// 除了最后一项以外，其余项都比上一项前面的系数多一；
// 转换：（用pos存储最后一项的数组下标）
// F(n)=F(n-1)+sum-n*nums[pos];
// 循环往复n次后，答案就有了

// 错位相减 
//（1）F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-2) * Bk[n-2] + (n-1) * Bk[n-1]
//（2）F(k+1) = 0 * Bk[n-1] + 1 * Bk[0] + 2 * Bk[2] + ... + (n-1) * Bk[n-2]
//（2）-（1）得：F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2]) - (n-1)*Bk[n-1]
// 得：F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2] + Bk[n-1]) - n*Bk[n-1]
// 令S=Sum{Bk}
// 有：F(k+1) = F(k) + S - n * Bk[n-1]


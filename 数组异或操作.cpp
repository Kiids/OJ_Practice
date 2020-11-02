/*
给你两个整数，n 和 start 。
数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。
请返回 nums 中所有元素按位异或（XOR）后得到的结果。
示例 1：
输入：n = 5, start = 0
输出：8
解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     "^" 为按位异或 XOR 运算符。
示例 2：
输入：n = 4, start = 3
输出：8
解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
示例 3：
输入：n = 1, start = 7
输出：7
示例 4：
输入：n = 10, start = 5
输出：2
提示：
1 <= n <= 1000
0 <= start <= 1000
n == nums.length
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = 0;
        for (int i = start; i < (start + n * 2); i += 2)
            ret ^= i;
        return ret;
    }
};

/*
异或的性质
1) 0 ^ x = x
2) x ^ x = 0
3) 2x ^ (2x+1) = 1
本题的主要思想：
将数列转为以偶数开头，以1为步长的数列，根据异或性质进行计算，得到结果后*2
然后再对最终的结果最后一位补上,最后一位单独做运算

1）当前的数列步长为2，但是目标的步长为1，这就需要我们对整个数列/2，即start/2，步长为1
    start为奇数的时候，那么根据公式2，可以添加2个 (start-1)进行异或，转为开头为偶数进行计算
        array(start, n) = (start-1) ^ array(start-1， n+1)，此时n=n+1
    start为偶数
        n为奇数，根据公式3，最终一共有 n/2个1 和 一个start+num-1 进行异或,即 res = (n/2)^1 & (start+num-1)
        n为偶数，根据公式3，最终一共有 n/2个1进行异或，即 res = (n/2)^1
    返回 res

2）对于1的处理，每个数/2，即把二进制数的最后一位去掉，统统向右挪动一位
    现在要恢复，需要向左挪动1位,即res = res * 2
    然后对最开始的数组进行最后一位的计算
        当且仅当start为奇数、n为奇数的时候，最后一位的异或计算为1，其余为零，
        if (start&1 && n&1)
            res += 1
最终的res即为最终结果
方法实现如下：
*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 2 * myxor(n, start/2);
        if (n & start & 1)
            ans += 1;
        return ans;
    }

    int myxor(int n, int start)
    {
        if (start & 1)
            return (start-1) ^ myxor(n+1, start-1);
        else
        {
            if (n & 1)
                return (start+n-1) ^ ((n/2) & 1);
            else
                return (n/2) & 1;
        }
    }
};

/*
给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
示例 1：
输入：n = 2
输出："110"
解释：(-2)2 + (-2)1 = 2
示例 2：
输入：n = 3
输出："111"
解释：(-2)2 + (-2)1 + (-2)0 = 3
示例 3：
输入：n = 4
输出："100"
解释：(-2)2 = 4
提示：
0 <= n <= 10^9
*/

class Solution {
    vector<int> baseK(int n, int k)
    {
        if (n == 0)
            return {0};

        vector<int> v;
        while (n != 0)
        {
            // int c = ((n % k) + abs(k)) % abs(k);
            int c = abs(n) % abs(k);
            v.push_back(c);
            n -= c;
            n /= k;
        }
        reverse(v.begin(), v.end());
        return v;
    }
public:
    string baseNeg2(int n) {
        vector<int> v = baseK(n, -2);
        string s;
        for (auto e : v)
            s += to_string(e);
        return s;
    }
};

// 数学推导 +K/-K 进制的通用转化法

// K>0时如下：
//        while (N != 0) {   
//            int r = N % K;
//            res.add(r);    // 产生的r时从个位到十位，百位...
//            N /= K;
//        }
// 推理K<0的情况
// （1）首先，K<0, 说明N在while过程中会正变负、负变正。K>0时N/=K没问题，都是正数，右移解决。
// 但K<0时，N/=K会导致漏了：当前while下K指数为奇数时增加的值.
// 比如K=-5, 指数为3，那么+(-5)^3是负数，就需要给N补上。
// 以2为底得到的二进制, 比-2得到的负二进制数，显得小，比如3: 2进制 011, -2进制 111. 这里的(-2)^2,正是由于(-2)^1而产生的。
// 所以，N/=K前需要加上：N -= r;
// （2）res add的值应该是正数，而当前的r = N%K, 由于N有可能为负，所以会导致r为负。
// 比如：-51%(-2)=-1. 为了产生正数的 int r，需要int r = abs(N)%abs(K). 从而得到：
//        while (N != 0) {   
//            int r = abs(N) % abs(K);
//            res.add(r);    //产生的r时从个位到十位，百位...
//            N -= r;
//            N /= K;
//        }

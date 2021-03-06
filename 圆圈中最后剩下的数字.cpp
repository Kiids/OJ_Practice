/*
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
示例 1：
输入: n = 5, m = 3
输出: 3
示例 2：
输入: n = 10, m = 17
输出: 2
限制：
1 <= n <= 10^5
1 <= m <= 10^6
*/

// 约瑟夫环 f(n,m)=[f(n-1,m)+m]%n
// https://blog.csdn.net/u011500062/article/details/72855826 

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0; // 剩下的最后一个数字的初始位置
        for(int i = 2; i <= n; i++)
            pos = (pos + m) % i;  // 循环右移
        
        return pos;
    }
};

// 以下方法会超时
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 0)
            return 0;
        
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i;
        
        auto b = v.begin();
        while (v.size() > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                b++;
                if (b == v.end())
                    b = v.begin();
            }

            b = v.erase(b);
            if (b == v.end())
                b = v.begin();
        }

        return v[0];
    }
}; 

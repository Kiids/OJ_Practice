/*
居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，
结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，
给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。
输入描述:
1≤n≤2^30,输入0结束程序。
输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3
12
0
输出
1
3
*/

// write your code here cpp
#include <iostream>
#include <algorithm>
using namespace std;

int Count(long long n)
{
    if (n == 1)
        return 0;
    else if (n <= 3)
        return 1;
    int metage = 0, rest = 0, count = 0;  // 天平上的钱，剩余的钱，称量次数
    metage = (n+2)/3;
    rest = n - 2*metage;
    count = 1 + Count(max(metage, rest));
    return count;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << Count(n) << endl;
    }
    return 0;
}

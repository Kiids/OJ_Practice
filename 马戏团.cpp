/*
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
输入描述:
首先一个正整数N，表示人员个数。 
之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
输出描述:
正整数m，表示罗汉塔的高度。
示例1
输入
6<br/>1 65 100<br/>2 75 80<br/>3 80 100<br/>4 60 95<br/>5 82 101<br/>6 81 70<br/>
输出
4
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct unit
{
    int id;
    int weight;
    int height;
};

bool cmp(unit u1, unit u2)
{
    if(u1.weight != u2.weight)
        return u1.weight < u2.weight;
    else
        return u1.height > u2.height;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<unit> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].id >> v[i].weight >> v[i].height;
        
        sort(v.begin(), v.end(), cmp);
        vector<int> dp(n,1);
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j]+1 > dp[i] && v[i].height >= v[j].height)
                    dp[i] = dp[j]+1;
            }
            if(dp[i] > max) 
                max = dp[i];
        }
        cout << max << endl;
    }
    return 0;
}
// 先判断体重递减，体重相同时，只有身高相同才能叠
// 体重升序排列，体重相同时，身高降序排列
// 再按照身高数据进行最大升序子序列。

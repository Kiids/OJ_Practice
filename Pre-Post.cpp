/*
We are all familiar with pre-order, in-order and post-order traversals of binary trees. A common problem in data structure classes is to find the pre-order traversal of a binary tree when given the in-order and post-order traversals. Alternatively, you can find the post-order traversal when given the in-order and pre-order. However, in general you cannot determine the in-order traversal of a tree when given its pre-order and post-order traversals. Consider the four binary trees below:
All of these trees have the same pre-order and post-order traversals. This phenomenon is not restricted to binary trees, but holds for general m-ary trees as well.
输入描述:
Input will consist of multiple problem instances. Each instance will consist of a line of the form m s1 s2, indicating that the trees are m-ary trees, s1 is the pre-order traversal and s2 is the post-order traversal.All traversal strings will consist of lowercase alphabetic characters. For all input instances, 1 <= m <= 20 and the length of s1 and s2 will be between 1 and 26 inclusive. If the length of s1 is k (which is the same as the length of s2, of course), the first k letters of the alphabet will be used in the strings. An input line of 0 will terminate the input.
输出描述:
For each problem instance, you should output one line containing the number of possible trees which would result in the pre-order and post-order traversals for the instance. All output values will be within the range of a 32-bit signed integer. For each problem instance, you are guaranteed that there is at least one tree with the given pre-order and post-order traversals.
示例1
输入
2 abc cba
2 abc bca
10 abc bca
13 abejkcfghid jkebfghicda
输出
4
1
45
207352860
*/

#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int ans, m;
char pre[27], post[27];
map<char, int> postidx;
// 相应字母在post中的下标,因为每个节点都是唯一的，所以可以建立一个索引
void Count(int preS, int preE, int postS, int postE);
int mCk(int m, int k);
 
int main()
{
    while (scanf("%d %s %s", &m, pre, post) != EOF)
    {
        ans = 1;
        for (int i = 0; i < strlen(post); i++)
            postidx[post[i]] = i;
        Count(0, strlen(pre) - 1, 0, strlen(post) - 1);
        printf("%d\n", ans);
    }
    return 0;
}
 
void Count(int preS, int preE, int postS, int postE)  // 指示先序和后序某段区间
{
    if (preS >= preE)
        return;
    int i = preS + 1, cnt = 0;  // cnt统计子树的个数,i是标识当前树的根节点的子树的根节点，在pre中的下标
    int idx = postidx[pre[i]];
    while (i <= preE)
    {
        Count(i, i + idx - postS, postS, idx);
        cnt++;
        if (idx != postE - 1)  // 子树不止一个,把要递归搜索的树的区间整体移动
        {
            i += idx - postS + 1;  // idx-postS是刚刚递归过的子树的大小
                                   // i要跨过这个区间，找到下一个要搜索的根节点
            postS = idx + 1;  // post的区间起始位置也要前进1位
            idx = postidx[pre[i]];  // idx重新定位下一个要搜索的子树根节点在post中的下标
        }
        else
            break;  //完成对当前区间中所有字数根节点的全部搜索
    }
    ans *= mCk(m, cnt);  //计算排列组合，cnt表示当前层有几个子树
}
 
int mCk(int m, int k)
{
    int numerator = 1, denominator = 1;
    for (int i = 0; i < k; i++, m--)
        numerator *= m;
    for (int i = 1; i <= k; i++)
        denominator *= i;
    return numerator / denominator;
}

//本质就是找到每一个根节点的子树
//因为是m叉树，所以可以得到当前根节点的子树有多少组合方式，再
//去到每一颗子树，如此递归直到找到所有叶子结点
//比如    abejkcfghid     jkebfghicda
//找到先序序列的第一个节点和后序序列的最后一个节点，这个节点就是当前的根节点
//当前的根→a bejk  cfghi  d         jkeb  fghic  d a
//            ↑    ↑     ↑           ↑     ↑ ↑
//                  找到3个区间，说明这一层有三颗子树
//遍历后序序列找到先序中根节点之后的节点，如果该点出现在根节点的前一个位置
//说明只有一颗子树，ans *= m (m叉树)
//不然就遍历整个后序序列，统计子树的个数k，然后算mCk ans*= mCk
//对这些子树所在的区间递归，直到只有一个节点，返回

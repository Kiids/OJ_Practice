/*
We are all familiar with pre-order, in-order and post-order traversals of binary trees. A common problem in data structure classes is to find the pre-order traversal of a binary tree when given the in-order and post-order traversals. Alternatively, you can find the post-order traversal when given the in-order and pre-order. However, in general you cannot determine the in-order traversal of a tree when given its pre-order and post-order traversals. Consider the four binary trees below:
All of these trees have the same pre-order and post-order traversals. This phenomenon is not restricted to binary trees, but holds for general m-ary trees as well.
��������:
Input will consist of multiple problem instances. Each instance will consist of a line of the form m s1 s2, indicating that the trees are m-ary trees, s1 is the pre-order traversal and s2 is the post-order traversal.All traversal strings will consist of lowercase alphabetic characters. For all input instances, 1 <= m <= 20 and the length of s1 and s2 will be between 1 and 26 inclusive. If the length of s1 is k (which is the same as the length of s2, of course), the first k letters of the alphabet will be used in the strings. An input line of 0 will terminate the input.
�������:
For each problem instance, you should output one line containing the number of possible trees which would result in the pre-order and post-order traversals for the instance. All output values will be within the range of a 32-bit signed integer. For each problem instance, you are guaranteed that there is at least one tree with the given pre-order and post-order traversals.
ʾ��1
����
2 abc cba
2 abc bca
10 abc bca
13 abejkcfghid jkebfghicda
���
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
// ��Ӧ��ĸ��post�е��±�,��Ϊÿ���ڵ㶼��Ψһ�ģ����Կ��Խ���һ������
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
 
void Count(int preS, int preE, int postS, int postE)  // ָʾ����ͺ���ĳ������
{
    if (preS >= preE)
        return;
    int i = preS + 1, cnt = 0;  // cntͳ�������ĸ���,i�Ǳ�ʶ��ǰ���ĸ��ڵ�������ĸ��ڵ㣬��pre�е��±�
    int idx = postidx[pre[i]];
    while (i <= preE)
    {
        Count(i, i + idx - postS, postS, idx);
        cnt++;
        if (idx != postE - 1)  // ������ֹһ��,��Ҫ�ݹ��������������������ƶ�
        {
            i += idx - postS + 1;  // idx-postS�Ǹոյݹ���������Ĵ�С
                                   // iҪ���������䣬�ҵ���һ��Ҫ�����ĸ��ڵ�
            postS = idx + 1;  // post��������ʼλ��ҲҪǰ��1λ
            idx = postidx[pre[i]];  // idx���¶�λ��һ��Ҫ�������������ڵ���post�е��±�
        }
        else
            break;  //��ɶԵ�ǰ�����������������ڵ��ȫ������
    }
    ans *= mCk(m, cnt);  //����������ϣ�cnt��ʾ��ǰ���м�������
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

//���ʾ����ҵ�ÿһ�����ڵ������
//��Ϊ��m���������Կ��Եõ���ǰ���ڵ�������ж�����Ϸ�ʽ����
//ȥ��ÿһ����������˵ݹ�ֱ���ҵ�����Ҷ�ӽ��
//����    abejkcfghid     jkebfghicda
//�ҵ��������еĵ�һ���ڵ�ͺ������е����һ���ڵ㣬����ڵ���ǵ�ǰ�ĸ��ڵ�
//��ǰ�ĸ���a bejk  cfghi  d         jkeb  fghic  d a
//            ��    ��     ��           ��     �� ��
//                  �ҵ�3�����䣬˵����һ������������
//�������������ҵ������и��ڵ�֮��Ľڵ㣬����õ�����ڸ��ڵ��ǰһ��λ��
//˵��ֻ��һ��������ans *= m (m����)
//��Ȼ�ͱ��������������У�ͳ�������ĸ���k��Ȼ����mCk ans*= mCk
//����Щ�������ڵ�����ݹ飬ֱ��ֻ��һ���ڵ㣬����

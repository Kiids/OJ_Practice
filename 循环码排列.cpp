/*
给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：
p[0] = start
p[i] 和 p[i+1] 的二进制表示形式只有一位不同
p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
示例 1：
输入：n = 2, start = 3
输出：[3,2,0,1]
解释：这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
示例 2：
输出：n = 3, start = 2
输出：[2,6,7,5,4,0,1,3]
解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
提示：
1 <= n <= 16
0 <= start < 2^n
*/

/*
任意n位的1<<n个格雷码gray[i]互不相同，刚好是{0,1,2,...,(1<<n)-1}的一个排列，且相邻两个格雷码只有一位不同，
首个格雷码和最后一个格雷码也只可视为相邻、也是只有一位不同。
所有格雷码异或上同一个值x，不改变上述性质：这是因为异或x后也是{0,1,2,...,(1<<n)-1}的一个排列，互不相同；
且相邻格雷码只有一位不同，异或任意值x后，相同的位还是相同，不同的位一定是一个0和一个1，异或x后还是一个1一个0，
只有一位不同。
从任意start值开始的格雷码，只需要都异或上同一个值x，使得首个格雷码为start即可：gray[0]^x==start，则x=gray[0]^start，
即g[i] = gray[i] ^ x = gray[i] ^ gray[0] ^ start。
x的一种直观解释：所有值都异或gray[0]，使得首个格雷码为0，再异或上start，使得首个格雷码为start，即x=gray[0]^start。
其中一种格雷码的直接构造方法为第i个值gray[i]=i^(i>>1)，恰好首个gray[0]=0，对应满足要求格雷码为：
g[i] = gray[i] ^ x = i^(i>>1) ^ 0 ^ start = i^(i>>1) ^ start
推广：保证任意第j个格雷码为gj的方法，先计算第j个原格雷码gray[j]，然后所有的值都异或x=gray[j]^gj即可：
g[i]=gray[i]^gray[j]^gj，其中异或gray[j]使得第j个值为0，异或gj即可使得第j个值为gj。
*/

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int x = 1 << n;
        vector<int> v(x, 0);
        for (int i = 0; i < x; i++)
            v[i] = i ^ (i >> 1) ^ start;
        return v;
    }
};

/*
有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？
连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。
输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。
示例 1：
输入：cont = [3, 2, 0, 2]
输出：[13, 4]
解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。
示例 2：
输入：cont = [0, 0, 3]
输出：[3, 1]
解释：如果答案是整数，令分母为1即可。
限制：
cont[i] >= 0
1 <= cont的长度 <= 10
cont最后一个元素不等于0
答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。
*/


class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        if (cont.size() == 1)
            return { cont[0], 1 };
        vector<int> b(cont.begin() + 1, cont.end());
        vector<int> t = fraction(b);
        return { cont[0] * t[0] + t[1], t[0] };
    }
};

// 递归关系f(n)=a0+1/f(n-1);n表示原数列，n-1表示原数列除掉第一个元素的数列
// 进一步:设f(n-1)=t1/t2,那么f(n)=a0+t2/t1=(a0*t1+t2)/t1
// 递归终止条件:n=1时。
// 题目中要求分子，分母互质，其实这必然互质，因为考虑最后两个数t(n-1)+1/t(n)，
// 分式是[t(n-1)t(n)+1]/t(n),分子是分母的整数倍加1，这必然是互质的，往前推，
// 设a/b中a,b是互质数，c为整数，那么c+b/a=(ca+b)/a,显然ca+b与a必然也互质的。
// 证明:假设(ca+b)/a = np/mp =(cmp+b)/mp,则b=(n-cm)p,此时a,b有公约数p，矛盾。
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        if (cont.size() == 1)
            return { cont[0],1 };
        vector<int>b(cont.begin()+1, cont.end());
        int t1 = fraction(b)[0];
        int t2 = fraction(b)[1];
        int m = cont[0]*t1+t2;
        int n = t1;
        return
        { m,n };
    }
};
// 优化一下，上面代码为了获得两个值执行了两次fraction，可以用一个数组存储
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        if (cont.size() == 1)
            return { cont[0],1 };
        vector<int>b(cont.begin()+1, cont.end());
        vector<int> t = fraction(b);
        return {cont[0]*t[0]+t[1],t[0]};
    }
};

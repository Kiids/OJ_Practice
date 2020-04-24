/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
提示：
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
*/

// 对称遍历
// 从左往右遍历累乘，结果保存在数组 ret 中，此时 ret[i] 表示，A[i] 左边所有元素的乘积
// 然后从右往左遍历累乘，获取 A[i] 右边所有元素的乘积
// 两边遍历之后得到的 ret，就是最终结果 
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ret(a.size(), 1);
        int l = 1, r = 1;
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] = l;
            l = l * a[i];
        }
        for (int i = ret.size() - 1; i >= 0; i--)
        {
            ret[i] *= r;
            r *= a[i];
        }
        return ret;
    }
};

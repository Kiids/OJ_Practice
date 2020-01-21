/*
给定一个全是正数的数组arr，定义一下arr的最小不可组成和的概念： 1，arr的所有非空子集中，
把每个子集内的所有元素加起来会出现很多的值，其中最小的记为min，最大的记为max； 2，在区间[min,max]上，
如果有一些正数不可以被arr某一个子集相加得到，那么这些正数中最小的那个，就是arr的最小不可组成和； 
3，在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和； 
举例： arr = {3,2,5} arr的min为2，max为10，在区间[2,10]上，4是不能被任何一个子集相加得到的值中最小的，
所以4是arr的最小不可组成和； arr = {3,2,4} arr的min为2，max为9，在区间[2,9]上，
8是不能被任何一个子集相加得到的值中最小的，所以8是arr的最小不可组成和； arr = {3,1,2} arr的min为1，max为6，
在区间[2,6]上，任何数都可以被某一个子集相加得到，所以7是arr的最小不可组成和； 请写函数返回arr的最小不可组成和。
*/

class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    int GetMin(vector<int> a)
    {
        sort(a.begin(), a.end());
        return a[0];
    }
    int GetMax(vector<int> a)
    {
        int ret = 0;
        for (auto e : a)
            ret += e;
        return ret;
    }
	int getFirstUnFormedNum(vector<int> arr, int len) {
        int min = GetMin(arr);
        int sum = GetMax(arr);
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; i++)
        {
        	//有len个数据--有len个阶段
			//{2， 3， 5}
			//i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2
			//i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3
			//i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
            for (int j = sum; j >= arr[i]; j--)
            {
            	//逆序判断背包承重中能够放入的数据
				//当数组中只有2的时候，背包承重从2-10都可以放入2的数值
				//当数组中放入2和3的时候，背包承重从5-10可以放入5，3-4放入
				//3，2只能放入2				
				//当数组中放入2，3，5时，背包承重10放入10，8-9放入8，7放入
				//7，5-6放入5...
				//dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的
				//重量后还能放置的最大重量
                if (dp[j] < dp[j - arr[i]] + arr[i])
                    dp[j] = dp[j - arr[i]] + arr[i];
                else
                    dp[j] = dp[j];
            }
        }
        for (int i = min; i <= sum; i++)
        {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
}; 

// 求数组的最小不可组成和arr = { 3, 2, 5 } arr的min为2，max为10，在区间[2, 10]上，
// 4是不能被任何一个子集相加得到的值中最小的，所以4是arr的最小不可组成和；
// 动态规划的01背包问题；根据承重和已有的重量种类阶段性计算当前承重时能够放入的重量；当数组中只有2重量的时候，背包承重从2 - 10都可以放入2的数值；当数组中放入2和3重量的时候，背包承重从5 - 10可以放入5；3 - 4放入3，2只能放入2；当数组中放入2，3，5重量时，背包承重10放入10，8 - 9放入8，7放入7，
// 5 - 6放入5…
// w 2 3 4 5 6 7 8 9 10
// 2 2 2 2 2 2 2 2 2 2 3 2 3 3 5 5 5 5 5 5 5 2 3 3 5 5 7 8 8 10
// 最终当每个承重与放入的重量不同时，这个承重就是最小不可求和-- - 4


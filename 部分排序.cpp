/*
给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。
示例：
输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
提示：
0 <= len(array) <= 1000000
*/

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (!array.size())
            return {-1, -1};
        vector<bool> dp(array.size(), true);
        int maxval = array[0];
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] < maxval)
                dp[i] = false;
            else
                maxval = array[i];
        }
        int minval = array[array.size()-1];
        int rmax = -1;
        int rmin = array.size();
        for (int i = array.size()-1; i >= 0; i--)
        {
            if (array[i] > minval)
                dp[i] = false;
            else
                minval = array[i];
                
            if (!dp[i])
            {
                rmax = max(rmax, i);
                rmin = min(rmin, i);
            }
        }
        if (rmax == -1)
            return {-1, -1};
        return {rmin, rmax};
    }
};

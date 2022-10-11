/*
车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
示例 1：
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
示例 2：
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
提示：
1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 10^5
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001, 0);
        for (auto trip : trips)
        {
            v[trip[1]] += trip[0];
            v[trip[2]] -= trip[0];
            int sum = 0;
            for (auto value : v)
            {
                sum += value;
                if (sum > capacity)
                    return false;
            }
        }
        return true;
    }
};

//题目即是否可以保证每时每刻车上的人数都<=capacity。把所有的人都安排在车上，然后判断是否每个时刻都满足总人数<=capacity即可
//差分数组d，对于每一个trip[i]，假如起点s，终点e，这批人数是cnt，那么差分数组的[s, e-1]位置+cnt。
//d[s] += cnt, d[e] -= cnt
//差分数组的前缀和就是原数组 性质
//对d数组前缀和，判断每个元素是否小于等于capacity即可
//时间复杂度O(n)


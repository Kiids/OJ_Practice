/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
在加热器的加热半径范围内的每个房屋都可以获得供暖。
现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:
输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:
输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
示例 3：
输入：houses = [1,5], heaters = [2]
输出：3
提示：
1 <= houses.length, heaters.length <= 3 * 10^4
1 <= houses[i], heaters[i] <= 10^9
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        heaters.insert(heaters.begin(), INT_MIN);
        heaters.push_back(INT_MAX);

        long long r = 0;
        int cur = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            while (cur < heaters.size() + 2)
            {
                if (heaters[cur] >= houses[i])
                    break;
                cur++;
            }
            r = max(r, min((long long)heaters[cur] - houses[i], (long long)houses[i] - heaters[cur - 1]));
        }
        return r;
    }
};

//需要保证每个房屋至少在一个加热器的供暖范围内，为了让加热半径最小，需要保证每个房屋最近的加热器的距离小于加热半径。
//全局最低的加热半径就等于所有房屋到最近加热器的距离中的最大值。 一个min(max)问题。
//房屋和加热器都是按照横坐标排序的；只需要顺次对每个房子找和他相邻的前后两个加热器即可。
//用两个指针分别标记房屋和加热器；不断移动加热器，直至加热器的横坐标大于房屋横坐标。 
//则当前加热器指针 cur 和 cur-1 就是房屋左边和右边的加热器。
//求两者到房屋距离中的较小值，就是该房屋最近的加热器到房屋的距离。
//遍历所有的房屋，取最大值。
//trick；由于最左边的加热器和最右边的加热器，可能就是比第一个房屋大或者比最后一个房屋小的，
//那cur-1或者cur很可能为-1或者n，这样有一些越界的问题。直接在左边和右边分别放置一个最远的加热器，
//它不会成为到房屋最近的加热器，但是不再需要处理边界条件。


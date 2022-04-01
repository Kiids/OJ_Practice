/*
有两个水壶，容量分别为 jug1Capacity 和 jug2Capacity 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到 targetCapacity 升。
如果可以得到 targetCapacity 升水，最后请用以上水壶中的一或两个来盛放取得的 targetCapacity 升水。
你可以：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: 
输入: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
输出: true
解释：来自著名的 "Die Hard"
示例 2:
输入: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
输出: false
示例 3:
输入: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
输出: true
提示:
1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10^6
*/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        int a = max(jug1Capacity, jug2Capacity);
        int b = min(jug1Capacity, jug2Capacity);
        int c = a + b;
        while (c)
        {
            if (c == targetCapacity)
                return true;

            if (c >= b)
                c -= b;
            else
                c += a;
        }
        return false;
    }
};

//先处理特殊情况，两壶相加刚好满足，或其中一壶刚好满足。
//规律只能通过大壶倒小壶产生新的数字：
//大壶容量a，小壶容量b，只能通过将大壶的水倒入小壶，然后再把小壶的水清空来产生新的容量数字，
//产生的新的数字是：a-b, a-2b, a-3b..., a-n*b直到大壶里剩余的水小于b升，
//此时，要想产生新的容量数字，也只有一个操作，即：
//将大壶剩余的数倒入小壶，然后大壶装满，产生了一个新的数字: 2a - n*b
//此时，要想产生新的容量数字，仍只有一个操作，即：
//从大壶里倒一点水将小壶补满，然后再把小壶清空，产生了一个新的数字: 2a - n*b - b

//用一个变量c表示当前总水量，
//当大壶水量够的时候，就不断减去小壶容量b，也就是不断的 c -= b，一边判断 c 是否等于 targetCapacity，
//当大壶水量不够的时候，就把剩余的水倒入小壶，然后加满大壶：c += a
//最终肯定能够刚好减成零，最坏的情况是大壶里装了b次水，那历史总装水量就是a * b, 是小壶容量的整数倍。
//实际情况是历史总装水是 a 和 b 的最小公倍数，减成零之后，下次相当于回到初始状态。
//如果在这个过程中没有搜索到，以后也不会搜索到了。
//把c初始化成a + b，这样特殊情况也顾及到了

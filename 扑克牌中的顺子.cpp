/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
示例 1:
输入: [1,2,3,4,5]
输出: True
示例 2:
输入: [0,0,1,2,5]
输出: True
限制：
数组长度为 5
数组的数取值为 [0, 13] .
*/

// 排序之后扑克牌有序，直接判断相邻两张牌之间需要多少个大王或小王填补
// 如果需要填补大小王的数量，大于已有大小王的数量，则返回 false 
// 相反，如果需要填补大小王的数量，小于或等于已有大小王的数量，则返回 true 
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 0;
        for (int i = 0; i < 4; i++)
        {
            if (nums[i] == 0)
            {
                n++;
                continue;
            }
            if (nums[i] == nums[i + 1])
                return false;
            n -= nums[i + 1] - nums[i] - 1;
        }
        return n >= 0;
    }
};

// 不排序 
//5 张扑克牌中的最大值 maxValue 和最小值 minValue ，使它为顺子需要 maxValue - minValue + 1 张牌
//在查找 maxValue 和 minValue 过程中，跳过大小王 0
//如果 maxValue - minValue + 1 > 5，说明题目给的 5 张牌不足以构成顺子，返回 false .
//即使里面有大小王，也不够用来填补使它构成顺子。
//如果 maxValue - minValue + 1 <= 5，说明 5 张牌足以构成顺子，返回 true。
//里面的大小王填补在合适位置即可。
//再定义一个标志数组判断是否有重复数字，发现重复数字直接返回 false。
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool m[15];
        memset(m, 0, sizeof(m));
        int minValue = 14, maxValue = 0;
        for (int item : nums) {
            if (item == 0) {
                continue;
            }
            if (m[item]) {
                return false;
            }
            m[item] = true;
            minValue = min(minValue, item);
            maxValue = max(maxValue, item);            
        }
        return maxValue - minValue + 1 <= 5;
    }
};

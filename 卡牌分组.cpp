/*
给定一副牌，每张牌上都写着一个整数。
此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。
示例 1：
输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：
输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：
输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：
输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：
输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]
提示：
1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        vector<int> v;
        for (auto e : deck)
            m[e] += 1;
        for (auto e : m)
            v.push_back(e.second);
        sort(v.begin(), v.end());

        for (int i = 2; i <= v[0]; i++)
        {
            int flag = 1;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] % i != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                return true;
        }
        return false;
    }
};

// 哈希表统计次数 & 判断最大公约数是否大于等于 2

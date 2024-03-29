/*
你在进行一个简化版的吃豆人游戏。你从 [0, 0] 点开始出发，你的目的地是 target = [xtarget, ytarget] 。地图上有一些阻碍者，以数组 ghosts 给出，第 i 个阻碍者从 ghosts[i] = [xi, yi] 出发。所有输入均为 整数坐标 。
每一回合，你和阻碍者们可以同时向东，西，南，北四个方向移动，每次可以移动到距离原位置 1 个单位 的新位置。当然，也可以选择 不动 。所有动作 同时 发生。
如果你可以在任何阻碍者抓住你 之前 到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者 同时 到达了一个位置（包括目的地） 都不算 是逃脱成功。
只有在你有可能成功逃脱时，输出 true ；否则，输出 false 。
示例 1：
输入：ghosts = [[1,0],[0,3]], target = [0,1]
输出：true
解释：你可以直接一步到达目的地 (0,1) ，在 (1, 0) 或者 (0, 3) 位置的阻碍者都不可能抓住你。 
示例 2：
输入：ghosts = [[1,0]], target = [2,0]
输出：false
解释：你需要走到位于 (2, 0) 的目的地，但是在 (1, 0) 的阻碍者位于你和目的地之间。 
示例 3：
输入：ghosts = [[2,0]], target = [1,0]
输出：false
解释：阻碍者可以和你同时达到目的地。 
提示：
1 <= ghosts.length <= 100
ghosts[i].length == 2
-10^4 <= xi, yi <= 10^4
同一位置可能有 多个阻碍者 。
target.length == 2
-10^4 <= xtarget, ytarget <= 10^4
*/

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int l = abs(target[0]) + abs(target[1]);  // 我到终点的距离
        for (vector<int> & e: ghosts)             // 比较阻碍者到终点的距离
            if (abs(target[0] - e[0]) + abs(target[1] - e[1]) <= l)
                return false;
        return true;
    }
};

//1.考虑当阻碍者比我离终点更远的情况，因为我离终点更近，阻碍者永远追不上我
//2.考虑当阻碍者比我离终点更近的情况，因为阻碍者可以优先到达终点，从而我无法通关
//以上，只需要对比我到终点的距离与阻碍者到终点的距离

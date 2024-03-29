/*
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。
每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。
如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。
就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。
给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：
dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。
示例 1：
输入：dominoes = "RR.L"
输出："RR.L"
解释：第一张多米诺骨牌没有给第二张施加额外的力。
示例 2：
输入：dominoes = ".L.R...LR..L.."
输出："LL.RR.LLRRLL.."
提示：
n == dominoes.length
1 <= n <= 10^5
dominoes[i] 为 'L'、'R' 或 '.'
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int l = 0;
        string ret = "";
        for (int r = 1; r < dominoes.size(); r++)
		{
            if (dominoes[r] == '.')
                continue;
            if (l != 0)
                ret += dominoes[l];
        
            int mid = r - l - 1;
            if (dominoes[l] == dominoes[r])
                ret += string(mid, dominoes[l]);
            else if (dominoes[l] == 'L' && dominoes[r] == 'R')
                ret += string(mid, '.');
            else
                ret += string(mid / 2, 'R') + (mid % 2 == 1 ? "." : "") + string(mid / 2, 'L');
            l = r;
        }
        return ret;
    }
};

//找出每个 . 左右两边最近的两个被推倒了的牌，然后判断这两个牌是什么样子的。
//双指针寻找 . 左右两边距离最近的被推倒的牌，形成 X....Y 区间。
//四种可能性：
//'R......R' => 'RRRRRRRR'
//'R......L' => 'RRRRLLLL' || 'RRRR.LLLL'
//'L......R' => 'L......R'
//'L......L' => 'LLLLLLLL'
//l指向区间的开始（指向 "L" 或 "R"）；
//r跳过所有的 "."，指向区间的结束（指向 "L" 或 "R"）。
//区间为 "X....Y"，判断这个区间左右端点的 "X"、 "Y"是什么，确定中间的 "."的状态。
// mid 表示区间内 "." 的个数。
 

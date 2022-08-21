/*
给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
示例 1：
输入：s = "abcabc"
输出：10
解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
示例 2：
输入：s = "aaacb"
输出：3
解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
示例 3：
输入：s = "abc"
输出：1
提示：
3 <= s.length <= 5 x 10^4
s 只包含字符 a，b 和 c 。
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ret = 0, a = -1, b = -1, c = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                a = i;
                ret += min(b, c) + 1;
            }
            else if (s[i] == 'b')
            {
                b = i;
                ret += min(a, c) + 1;
            }
            else
            {
                c = i;
                ret += min(a, b) + 1;
            }
        }
        return ret;
    }
};


class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3];
        cnt[0] = -1;
        cnt[1] = -1;
        cnt[2] = -1;

        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 'a'] = i;
            // 这里求全部最小值即可，不需要判断是a或b或c的情况
            ret += min(cnt[0], min(cnt[1], cnt[2])) + 1;
        }
        return ret;
    }
};

//对于当前出现a，那么去看b,c的上次出现位置的最小值 x
//那么0~i, 1~i到x~i 之间一共 x+1的字符串都是新引入的（因为i是新的）
//单次遍历，累加x+1结果即可，计算后会更新a的最新位置


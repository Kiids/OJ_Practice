/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能?重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：
输入：s = "0000"
输出：["0.0.0.0"]
示例 3：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
提示：
1 <= s.length <= 20
s 仅由数字组成
*/

class Solution {
    int n;
    vector<string> v;
    // u当前搜到字符串的第几个位置
    // cnt将字符串分割成了满足要求的几部分
    void DFS(string& s, int u, int cnt, string path)
    {
        if (u == n && cnt == 4)
        {
            path.pop_back();
            v.push_back(path);
            return;
        }
        if (u == n || cnt > 4)  // 剪枝
            return;
        for (int i = u; i < n; i ++ )
        {
            string str = s.substr(u, i - u + 1);
            if ((str[0] == '0' && str.size() > 1) || str.size() > 3)  // 如果有前导0，或者分割的数字大于3位，直接返回
                return;
            int x = stoi(str);
            if (x >= 0  && x <= 255)
                DFS(s, i + 1, cnt + 1, path + str + '.');
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        DFS(s, 0, 0, "");
        return v;
    }
};

//从当前位置往后分割字符串，分割到合法的子串后，向下一个位置搜，搜素过程中剪枝。


/*
一个 「开心字符串」定义为：
仅包含小写字母 ['a', 'b', 'c'].
对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。
给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。
请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。
示例 1：
输入：n = 1, k = 3
输出："c"
解释：列表 ["a", "b", "c"] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 "c" 。
示例 2：
输入：n = 1, k = 4
输出：""
解释：长度为 1 的开心字符串只有 3 个。
示例 3：
输入：n = 3, k = 9
输出："cab"
解释：长度为 3 的开心字符串总共有 12 个 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"] 。第 9 个字符串为 "cab"
示例 4：
输入：n = 2, k = 7
输出：""
示例 5：
输入：n = 10, k = 100
输出："abacbabacb"
提示：
1 <= n <= 10
1 <= k <= 100
*/

class Solution {
public:
    string getHappyString(int n, int k) {
        char abc[3] = {'a', 'b', 'c'};
        char ch[3][2] = {{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
        int state[3][2] = {{1, 2}, {0, 2}, {0, 1}};
        if (k > (int)pow(2, n - 1) * 3)
            return "";
        string s;
        k--;
        int p = k / (int)pow(2, n - 1);
        k %= (int)pow(2, n - 1);
        s.push_back(abc[p]);
        for (int i = n - 1; i > 0; i--)
        {
            int tmp = (int)pow(2, i - 1);
            s.push_back(ch[p][k / tmp]);
            p = state[p][k / tmp];
            k %= tmp;
        }
        return s;
    }
};

//相当于在三颗二叉树中，通过计算结点个数求解。
//需要注意相邻的两个字符不相同，所以这里使用定义状态的方法


class Solution {
    vector<string> v;
    void DFS(int n, int cur, string t)
    {
		if (cur == n)
        {
			v.push_back(t);
			return;
		}			
		if (check(t, 'a'))DFS(n, cur + 1, t + 'a');
		if (check(t, 'b'))DFS(n, cur + 1, t + 'b');
		if (check(t, 'c'))DFS(n, cur + 1, t + 'c');
	}
	bool check(string &t, char a)
    {
		if (t.empty())
            return true;
		return t[t.size() - 1] != a;
	}
public:
    string getHappyString(int n, int k) {
		DFS(n, 0, "");
		if (v.size() < k)
            return "";
		else return v[k - 1];
    }
};

//回溯
//判断要添加的字符与当前字符串的关系，若当前字符串为空或当前字符串最后一个字符与要添加字符不同，则可添加字符，否则不能添加字符，
//因为递归顺序是a,b,c依次添加的，所以添加的字符串的排序是按字典序从小到大依次排序的，最后判断数组的大小是否大于k，
//若大于，则返回数组中第k个字符串，否则返回空字符串。


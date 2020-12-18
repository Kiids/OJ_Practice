/*
你有一个日志数组 logs。每条日志都是以空格分隔的字串。
对于每条日志，其第一个字为字母与数字混合的 标识符 ，除标识符之外的所有字为这一条日志的 内容 。
除标识符之外，所有字均由小写字母组成的，称为 字母日志
除标识符之外，所有字均由数字组成的，称为 数字日志
题目所用数据保证每个日志在其标识符后面至少有一个字。
请按下述规则将日志重新排序：
所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序；
数字日志 应该按原来的顺序排列。
返回日志的最终顺序。
示例 ：
输入：["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
提示：
0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] 保证有一个标识符，并且标识符后面有一个字。
*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp_stable);
        return logs;
    }

    static bool cmp_stable(const string &a, const string &b)
    {
        int pa = 0;
        int pb = 0;
        while (a[pa++] != ' ');
        while (b[pb++] != ' ');
        bool aIsNumberLog = a[pa] >= '0' && a[pa] <= '9';
        bool bIsNumberLog = b[pb] >= '0' && b[pb] <= '9';
        
        if (!aIsNumberLog && bIsNumberLog)
            return true;
        if (aIsNumberLog && !bIsNumberLog)
            return false;
        if (aIsNumberLog && bIsNumberLog)
            return false;
        // return false 的话，若a和b都是数字日志且相等，那么它们将会保持原来的顺序

        int cmp = a.compare(pa, -1, b, pb, -1);
        if (cmp == 0)
            return a.compare(0, pa, b, 0, pb) <= 0;
        else if (cmp < 0)
            return true; // a is lower
        else
            return false;
    }
};

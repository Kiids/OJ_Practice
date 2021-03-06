// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
// 案例:
// s = "leetcode"
// 返回 0.
// s = "loveleetcode",
// 返回 2.
// 注意事项：您可以假定该字符串只包含小写字母。

class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = {0};
        int size = s.size();
        for (int i = 0; i < size; i++)
            count[s[i]]++;
        for (int i = 0; i < size; i++)
            if (count[s[i]] == 1)
                return i;
        return -1;
    }
};


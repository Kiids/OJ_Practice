/*
稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
示例1:
 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:
 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4
提示:
words的长度在[1, 1000000]之间
*/

class Solution {
public:
    int findString(vector<string>& words, string s) {
        if (words.size() == 0)
            return -1;
        int l = 0, r = words.size() - 1;
        while (l <= r)
        {
            while (l <= r && words[l] == "")
                l++;
            while (l <= r && words[r] == "")
                r--;
            int m = l + (r - l) / 2;
            while (m < r && words[m] == "")
                m++;
            if (words[m] == s)
                return m;
            else if (words[m] > s)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

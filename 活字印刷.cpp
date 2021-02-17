/*
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
注意：本题中，每个活字字模只能使用一次。
示例 1：
输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：
输入："AAABBC"
输出：188
提示：
1 <= tiles.length <= 7
tiles 由大写英文字母组成
*/

class Solution {
public:
    int ret;
    int numTilePossibilities(string tiles) {
        vector<int> mp(26, 0);
        for (char& ch : tiles)
            ++mp[ch - 'A'];
        for (int i = 0, j = 0; i < 26; i++)
            if (mp[i] != 0)
                swap(mp[i], mp[j++]);  //把数量是0的字母去掉
        mp.resize(tiles.size());
        dfs(mp);
        return ret;
    }

    void dfs(vector<int>& v)
    {
        for (auto& e : v) 
        {
            if (e != 0) 
            {
                e--;
                ret++;
                dfs(v);
                e++;
            }
        }
    }
};

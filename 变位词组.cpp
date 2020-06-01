/*
编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。
注意：本题相对原题稍作修改
示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            m[t].push_back(i);
        }
        for (auto e : m)
        {
            vector<string> v;
            auto i = e.second;
            for (auto index : i)
                v.push_back(strs[index]);
            ret.push_back(v);
        }
        return ret;
    }
};

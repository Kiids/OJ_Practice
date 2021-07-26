/*
给定一个字符串数组，将字母异位词组合在一起。可以按任意顺序返回结果列表。
字母异位词指字母相同，但排列不同的字符串。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; 
        for (string &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> v;
        for (auto i = m.begin(); i != m.end(); i++)
            v.push_back(i->second);
        return v;
    }
};

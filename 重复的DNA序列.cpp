/*
DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。
给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。
示例 1：
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：
输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
提示：
0 <= s.length <= 10^5
s[i]=='A'、'C'、'G' or 'T'
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st;
        int n = s.size();
        vector<string> v;
        for (int i = 0; i + 10 <= n; i++)
        {
            string t = s.substr(i, 10);
            if (st.count(t))
                v.push_back(t);
            else
                st.insert(t);
        }

        sort(v.begin(), v.end());
        // it 迭代器，unique函数将重复出现的元素放到数组末尾,并返回这部分元素第一个出现的位置，最终从该位置开始删除后面所有元素即可
        auto it = unique(v.begin(), v.end());
        v.erase(it, v.end());
        return v;
    }
};

//利用一个集合 set 或哈希表 unordered_map 记录一个字符串出现与否或出现的次数
//遍历字符串，若当前位置 i 开头的长度为 10 的子字符串曾出现过，则存入结果数组。否则将该子字符串计入集合或哈希表。
//由于可能出现某一个子字符串多次出现，每次都被存入结果数组，最后对结果数组去重。

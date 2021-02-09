/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(s);
        string str;
        for (char c : pattern)
        {
            if (!(ss >> str) || (map.count(c) == 1 && map[c] != str) || (rmap.count(str) == 1 && rmap[str] != c))
                return false;
            map[c] = str;
            rmap[str] = c;
        }
        return (ss >> str) ? false : true;
    }
};

//定义两个map，防止[aaaa]与[cat dog dog cat]、[abba]与[cat cat cat cat]时输出true
//用stringstream自动输出词组
//判断：!(ss >> s)判断pattern长度是否大于str长度，且将ss容器中字符串赋值给s
//判断：(map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) 来判断是否匹配
//判断：(ss >> s) ? false : true 判断str长度是否大于pattern长度

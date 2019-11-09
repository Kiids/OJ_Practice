// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

// 用于映射的字符串数组
string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// 总计深度为digits.size()层的递归，每层递归在字符串中进行字符的组合
class Solution {
public:
    void combineStr(const string& digits, size_t index, const string& str, vector<string>& strs)
    {
        if (index == digits.size())
        {
            strs.push_back(str);
            return;
        }
        
        // 获取数字对应的字符数组
        string letters = letterMap[digits[index] - '0'];
        for (size_t i = 0; i < letters.size(); ++i)
        {
            combineStr(digits, index+1, str+letters[i], strs);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> strs;
        
        if (digits.empty())
            return strs;
        
        size_t index = 0;
        string str;
        
        combineStr(digits, index, str, strs);
        
        return strs;
    }
};


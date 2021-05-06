/*
全字母句 指包含英语字母表中每个字母至少一次的句子。
给你一个仅由小写英文字母组成的字符串 sentence ，请你判断?sentence 是否为 全字母句 。
如果是，返回 true ；否则，返回 false 。
示例 1：
输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
输出：true
解释：sentence 包含英语字母表中每个字母至少一次。
示例 2：
输入：sentence = "leetcode"
输出：false
提示：
1 <= sentence.length <= 1000
sentence 由小写英语字母组成
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int v[26] = {0}, x = 0;
    	for (int i = 0; i < sentence.length(); i++)
    		v[sentence[i] - 'a'] = 1;
    	for (int i = 0; i < 26; i++)
    		x += v[i];
    	return x == 26;
    }
};

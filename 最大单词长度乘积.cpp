/*
给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
示例 1：
输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
输出：16 
解释：这两个单词为 "abcw", "xtfn"。
示例 2：
输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
输出：4 
解释：这两个单词为 "ab", "cd"。
示例 3：
输入：words = ["a","aa","aaa","aaaa"]
输出：0 
解释：不存在这样的两个单词。
提示：
2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母
*/

class Solution {
public:
    int v[1004];
    int maxProduct(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                v[i] |= (1 << (words[i][j] - 'a'));
                
        int ret = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (!(v[i] & v[j]))
                    ret = max(ret, int(words[i].size() * words[j].size()));
                    
        return ret;
    }
};

//状态压缩
//对于每一个字符串 word[i]，是否包含 26 个英文字母，用一个32位二进制数字表示，
//二进制位第[0,25]位，分别对应[a,z],每一位的状态为0或1，0表不存在该字母，1表示存在该字母，
//因此可以利用位运算O(1)判断两个字符words[i]和words[j]是否有公共字母
//时间复杂度：O(n^2)
//空间复杂度：O(n)

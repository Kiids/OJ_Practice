/*
����һ���ǿ��ַ��� s ��һ�������ǿյ��ʵ��б� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�
˵����
���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��
����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
ʾ�� 2��
����: s = "applepenapple", wordDict = ["apple", "pen"]
���: true
����: ���� true ��Ϊ "applepenapple" ���Ա���ֳ� "apple pen apple"��
     ע��������ظ�ʹ���ֵ��еĵ��ʡ�
ʾ�� 3��
����: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
���: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};

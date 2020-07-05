/*
�����ֵ��е������ʣ�������ȡ�дһ����������һ����ת������һ���ʣ� ����һ��ֻ�ܸı�һ���ַ���ÿһ���õ����´ʶ����������ֵ����ҵ���
��дһ�����򣬷���һ�����ܵ�ת�����С����ж�����ܵ�ת�����У�����Է����κ�һ����
ʾ�� 1:
����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
���:
["hit","hot","dot","lot","log","cog"]
ʾ�� 2:
����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
���: []
����: endWord "cog" �����ֵ��У����Բ����ڷ���Ҫ���ת�����С�
*/

class Solution {
public:
    bool canTranslate(string& from_, string& to_)
    {
        if (from_.size() != to_.size())
            return false;
        int count = 0;
        for (int i = 0; i < from_.size(); i++)
            if(from_[i] != to_[i]) 
                count++;
        return count == 1;
    }

    bool hasRoute(string& curWord, string& endWord, vector<string>& wordList, vector<bool>& visited, vector<string>& result)
    {
        if(curWord == endWord)
            return true;
        for(int i = 0; i < wordList.size(); i++)
        {
            if (visited[i] || !canTranslate(curWord, wordList[i]))
                continue;
            visited[i] = true;
            result.push_back(wordList[i]);
            if(hasRoute(wordList[i], endWord, wordList, visited, result))
                return true;
            result.pop_back();
        }
        return false;
    }

    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<string> result = {beginWord};
        vector<bool> visited(wordList.size(), false);
        if (hasRoute(beginWord, endWord, wordList, visited, result))
            return result;
        return vector<string>();
    }
};

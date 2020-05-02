/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ����磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������
[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]
�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
ʾ�� 1��
���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
�����true
ʾ�� 2��
���룺board = [["a","b"],["c","d"]], word = "abcd"
�����false
��ʾ��
1 <= board.length <= 200
1 <= board[i].length <= 200
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
    {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1 && word[k] == board[i][j])
            return true;
        char t = board[i][j];
        board[i][j] = '1';
        bool ret = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = t;
        return ret; 
    }
};

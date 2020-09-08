/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
提示：
board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0)
            return false;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (DFS(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>>& v, string w, int i, int j, int wi)
    {
        if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] != w[wi])
            return false;

        if (wi == w.size() - 1)
            return true;

        char t = v[i][j];
        v[i][j] = ' ';
        bool ret = DFS(v, w, i - 1, j, wi + 1) || DFS(v, w, i + 1, j, wi + 1) || DFS(v, w, i, j - 1, wi + 1) || DFS(v, w, i, j + 1, wi + 1);
        v[i][j] = t;
        return ret;
    }
};

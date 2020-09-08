/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
ʾ��:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
���� word = "ABCCED", ���� true
���� word = "SEE", ���� true
���� word = "ABCB", ���� false
��ʾ��
board �� word ��ֻ������д��СдӢ����ĸ��
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

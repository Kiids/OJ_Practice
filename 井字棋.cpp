// 对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。 
// 给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
// 测试样例：
// [[1,0,1],[1,-1,-1],[1,-1,0]]
// 返回：true

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == 1 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
        }
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == 1 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        return false;
    }
};

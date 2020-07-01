/*
���һ���㷨���ж�����Ƿ�Ӯ�˾�����Ϸ��������һ�� N x N ���������̣����ַ�" "��"X"��"O"��ɣ������ַ�" "����һ����λ��
�����Ǿ�����Ϸ�Ĺ���
����������ַ������λ��" "���С�
��һ��������Ƿ��ַ�"O"���ҵڶ���������Ƿ��ַ�"X"��
"X"��"O"ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
����N����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ��������Ӧ���ַ�����һ�ʤ��
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
�����Ϸ���ڻ�ʤ�ߣ��ͷ��ظ���Ϸ�Ļ�ʤ��ʹ�õ��ַ���"X"��"O"���������Ϸ��ƽ�ֽ������򷵻� "Draw"������Ի����ж�����Ϸδ���������򷵻� "Pending"��
ʾ�� 1��
���룺 board = ["O X"," XO","X O"]
����� "X"
ʾ�� 2��
���룺 board = ["OOX","XXO","OXO"]
����� "Draw"
���ͣ� û����һ�ʤ�Ҳ����ڿ�λ
ʾ�� 3��
���룺 board = ["OOX","XXO","OX "]
����� "Pending"
���ͣ� û����һ�ʤ���Դ��ڿ�λ
��ʾ��
1 <= board.length == board[i].length <= 100
����һ����ѭ���������
*/

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int bSize=board.size(), N = board.size();
        int sum_row = 0, sum_col = 0, sum_dia_right = 0, sum_dia_left = 0, isFull = 1;
        for (int i = 0; i < bSize; i++)
        {
            sum_row = 0, sum_col = 0;
            sum_dia_left += board[i][i];           //���Խ����
            sum_dia_right += board[i][bSize-1-i];  //���Խ����
            for (int j = 0; j < bSize; j++)
            {
                sum_row += board[i][j]; //�����
                sum_col += board[j][i]; //�����
                if (board[i][j] == ' ')
                    isFull =0;
            }
            if (sum_row == ((int)'X') * N || sum_col == ((int)'X') * N)
                return string("X");
            if (sum_row == ((int)'O') * N || sum_col == ((int)'O') * N)
                return string("O");
        }
        if (sum_dia_left == ((int)'X') * N || sum_dia_right == ((int)'X') * N)
            return string("X");
        if (sum_dia_left == ((int)'O') * N || sum_dia_right == ((int)'O') * N)
            return string("O");
        if (isFull)  //û��ѡ�ֻ�ʤ
            return string("Draw");
        else
            return string("Pending");
    }
};
